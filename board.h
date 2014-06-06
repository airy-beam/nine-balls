// 
// File:   board.h
// Author: ????????
//
// Created on 27 Декабрь 2008 г., 21:13
//

#ifndef _BOARD_H
#define	_BOARD_H

#include <iostream>
#include "tree.h"
#include "stdafx.h"

using std::vector;
using std::list;

class Board
{
public:
    Board();
    ~Board();
    
    enum Players { Max, Min };
    
    static const int NumberOfCells = 9;
    static int MaxDepth;
    void initialize();
    bool game_over();
    
    bool is_legal(int);
    Board* make_move(int);
    
    Players turn;
    int move;
    int cells[NumberOfCells * 2 + 1];
	int last_index;
    int MaxBoiler;
    int MinBoiler;
    int MaxSacred;
    int MinSacred;
    
    typedef signed int evaluation;
    void set_eval(evaluation);
    evaluation get_eval();
    
    vector<Board*> generate_moves();
    int find_best_move();
    evaluation evaluate();
    
    void show();
    int unfold(Tree<Board>::TreeNode * node, int depth);
    
private:
    evaluation eval;
};

#endif	/* _BOARD_H */

