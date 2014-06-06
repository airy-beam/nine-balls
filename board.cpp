#include "stdafx.h"
#include "board.h"
#include "tree.cpp"

int Board::MaxDepth;

Board::Board()
{
    
}

Board::~Board()
{
    
}

void Board::initialize()
{
    for (int i = 1; i <= NumberOfCells * 2; i++)
        this->cells[i] = 9;
    this->MaxBoiler = 0;
    this->MinBoiler = 0;
    this->MaxSacred = 0;
    this->MinSacred = 0;
    this->turn = Max;
	this->last_index = 0;
}

bool Board::game_over()
{
	if ((this->MaxBoiler > 81) || (this->MinBoiler > 81)) return true;

    bool all_empty = true;
    for (int i = 1; i <= 9; i++)
        if ( 0 != this->cells[i]) all_empty = false;
    if (all_empty) return true;
    
    all_empty = true;
    for (int i = 10; i <= 18; i++)
        if ( 0 != this->cells[i]) all_empty = false;
    if (all_empty) return true;
    
    return false;
}

bool Board::is_legal(int move)
{
    if ((Max == this->turn) &&
        (1 <= move) && ( move <= 9) &&
        (this->cells[move] != 0))
    {
        return true;
    }
    if ((Min == this->turn) &&
        (10 <= move) && ( move <= 18) &&
        (this->cells[move] != 0))
    {
        return true;
    }
    return false;
}

Board::evaluation Board::evaluate()
{
    evaluation eval = 0;
    eval = (this->MaxBoiler - this->MinBoiler) * 5;
    if ( 0 != this->MaxSacred ) eval += 100;
    if ( 0 != this->MinSacred ) eval -= 100;
    for (int i = 1; i <= 9; i++)
        eval += this->cells[i];
    for (int i = 10; i <= 18; i++)
        eval -= this->cells[i];
    return eval;
}

vector<Board*> Board::generate_moves()
{
    vector<Board*> newPositions;
    int from_index, to_index;
    if (Max == this->turn)
    {
        from_index = 1;
        to_index = 9;
    }
    else
    {
        from_index = 10;
        to_index = 18;
    }
    
    for (int i = from_index; i <= to_index; i++)
    {
        if ( 0 != this->cells[i] )
        {
            Board * newPosition = this->make_move(i);
            newPositions.push_back(newPosition);
        }
    }
    return newPositions;
}

Board* Board::make_move(int cell)
{
    Board * newPosition = new Board;
    *newPosition = *this;
    int last_index;   //where the last ball falls
    int last_balls;   //and how many balls become in that cell
    if ( newPosition->cells[cell] == 1 )
    {
        newPosition->cells[cell] = 0;
        last_index = cell + 1;
        if (last_index > 18) last_index = 1;
        (newPosition->cells[last_index]) += 1;
        last_balls = newPosition->cells[last_index];
    }
    if ( newPosition->cells[cell] > 1 )
    {
        int move_to = cell;
        int stones = newPosition->cells[cell];
        newPosition->cells[cell] = 0;
        while ( 0 != stones )
        {
            last_index = move_to;
            newPosition->cells[move_to]++;
            move_to = move_to + 1;
            if (move_to > 18) move_to = 1;
            stones--;
        }
        last_balls = newPosition->cells[last_index];
    }
    if (last_balls % 2 == 0)
    {
        if ((Max == newPosition->turn) &&
            (last_index >= 10) )
        {
            newPosition->MaxBoiler += newPosition->cells[last_index];
            newPosition->cells[last_index] = 0;
        }
        if ((Min == newPosition->turn) &&
            (last_index <= 9) )
        {
            newPosition->MinBoiler += newPosition->cells[last_index];
            newPosition->cells[last_index] = 0;
        }
    }
    if (last_balls == 3 && last_index != 9 && last_index != 18)
    {
        if ((0 == newPosition->MaxSacred) &&
            (Max == newPosition->turn) &&
            (newPosition->MinSacred != last_index - 9) &&
            (last_index >= 10))
        {
            newPosition->MaxSacred = last_index;
        }
        if ((0 == newPosition->MinSacred) &&
            (Min == newPosition->turn) &&
            (newPosition->MaxSacred != last_index + 9) &&
            (last_index <= 9))
        {
            newPosition->MinSacred = last_index;
        }
    }
    if (0 != newPosition->MaxSacred)
    {
        newPosition->MaxBoiler += newPosition->cells[newPosition->MaxSacred];
        newPosition->cells[newPosition->MaxSacred] = 0;
    }
    if (0 != newPosition->MinSacred)
    {
        (newPosition->MinBoiler) += newPosition->cells[newPosition->MinSacred];
        newPosition->cells[newPosition->MinSacred] = 0;
    }
    if ( true == newPosition->game_over() )
    {
        for (int i = 1; i <= 9; i++)
        {
            (newPosition->MaxBoiler) += (newPosition->cells[i]);
            (newPosition->cells[i]) = 0;
        }
        for (int i = 10; i <= 18; i++)
        {
            (newPosition->MinBoiler) += (newPosition->cells[i]);
            (newPosition->cells[i]) = 0;
        }
    }
    
    newPosition->move = cell;
	newPosition->last_index = last_index;
    if (Max == newPosition->turn) 
        newPosition->turn = Min;
    else
        newPosition->turn = Max;
    return newPosition;
}

void Board::show()
{
    for (int i = 18; i >= 10; i--)
        std::cout << this->cells[i] << " ";
	std::cout << std::endl;
    std::cout << this->MinBoiler << "               " << this->MaxBoiler << std::endl;
    for (int i = 1; i <= 9; i++)
        std::cout << this->cells[i] << " ";
    std::cout << std::endl;
    if ( 0 != this->MaxSacred) std::cout << "Max sacred: " << this->MaxSacred << std::endl;
    if ( 0 != this->MinSacred) std::cout << "Min sacred: " << this->MinSacred << std::endl;
    std::cout << std::endl;
} 

int Board::find_best_move()
{
    Tree<Board> decisionTree(*this);
    return unfold(decisionTree.get_root( ), 1);
}

int Board::unfold(Tree<Board>::TreeNode * node, int depth)
{
    vector<Board*> child_positions = node->get_data().generate_moves();
    if ( 0 != child_positions.size() ) node->add_children(child_positions);
            
	if ( 0 != child_positions.size() && depth < Board::MaxDepth)
    {
        Tree<Board>::TreeNode::NodesList children = node->get_children();
        Tree<Board>::TreeNode::NodesIterator p;
        for (p = children.begin(); p != children.end(); ++p)
        {
            Board::unfold(*p, depth + 1);
        }

        vector<evaluation> eval_of_children;
        for (p = children.begin(); p != children.end(); ++p)
        {
            eval_of_children.push_back((*p)->get_data().get_eval());
        }
        if (Max == node->get_data().turn)
        {
            evaluation max_eval = eval_of_children[0];
            for (int i = 0; i < eval_of_children.size(); i++)
                if (eval_of_children[i] > max_eval) max_eval = eval_of_children[i];
            node->get_data().set_eval(max_eval);
        }
        else
        {
            evaluation min_eval = eval_of_children[0];
            for (int i = 0; i < eval_of_children.size(); i++)
                if (eval_of_children[i] < min_eval) min_eval = eval_of_children[i];
            node->get_data().set_eval(min_eval);
        }
    }
    else
    {
        node->get_data().set_eval( node->get_data().evaluate( ) );
    }
    
    if (1 == depth)
    {
        Tree<Board>::TreeNode::NodesList children = node->get_children();
        evaluation best_eval = node->get_data().get_eval();
        for (Tree<Board>::TreeNode::NodesIterator p = children.begin(); p != children.end(); ++p)
        {
            if (best_eval == (*p)->get_data().get_eval())
            {
				//_CrtDumpMemoryLeaks();
                return (*p)->get_data().move;
            }
        }
    }
}

void Board::set_eval(Board::evaluation a)
{
    this->eval = a;
}

Board::evaluation Board::get_eval()
{
    return this->eval;
}
