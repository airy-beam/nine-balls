#include "stdafx.h"
#include "tree.h"

template<class T>
Tree<T>::Tree()
{
    this->root = 0;
}

template<class T>
Tree<T>::Tree(T data)
{
    TreeNode * root_node = new TreeNode(data, 0);
    this->root = root_node;
}

template<class T>
Tree<T>::~Tree()
{
    delete root;
}

template<class T>
typename Tree<T>::TreeNode * Tree<T>::get_root()
{
    return this->root;
}

template<class T>
Tree<T>::TreeNode::TreeNode()
{
    this->data = 0;
    this->parent = 0;
}

template<class T>
Tree<T>::TreeNode::TreeNode(T data, typename Tree<T>::TreeNode * parent)
{
    this->data = data;
    this->parent = parent;
}

template<class T>
Tree<T>::TreeNode::~TreeNode()
{
    this->delete_subtree();
}

template<class T>
T& Tree<T>::TreeNode::get_data()
{
    return data;
}

template<class T>
void Tree<T>::TreeNode::set_data(T data)
{
    this->data = data;
}

template<class T>
void Tree<T>::TreeNode::delete_node()
{
    NodesIterator p = find(this->parent->children.begin(),
                           this->parent->children.end(),
                           this);
    this->parent->children.erase(p);
    delete this;
}

template<class T>
void Tree<T>::TreeNode::delete_subtree()
{
    if (0 != this->children.size())
    {
        for (NodesIterator p = (this->children).begin( );
             p != (this->children).end( );
             ++p )
        {
            delete *p;
            //p = this->children.erase(p);
            //this->children.erase(p);
        }
    }
    this->children.clear();
}

template<class T>
void Tree<T>::TreeNode::add_child(T data)
{
    TreeNode * child = new TreeNode(data, this);
    this->children.push_back(child);
}

template<class T>
void Tree<T>::TreeNode::add_children(vector<T*> data)
{
    typename vector<T*>::iterator p;
    for (p = data.begin(); p != data.end(); ++p)
    {
        this->add_child(*(*p));
        delete (*p);
    }
}

template<class T>
int Tree<T>::TreeNode::count_children()
{
    return this->children.size();
}

template<class T>
list<typename Tree<T>::TreeNode *> Tree<T>::TreeNode::get_children()
{
    return this->children;
}

template<class T>
typename Tree<T>::TreeNode * Tree<T>::TreeNode::get_parent()
{
    return this->parent;
}
