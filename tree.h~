// 
// File:   tree.h
// Author: Iskander Zharkenov
//
// Created on 27 Декабрь 2008 г., 16:09
//

#ifndef _TREE_H
#define	_TREE_H

#include <list>
#include <vector>
#include <algorithm>
#include "stdafx.h"

using std::vector;
using std::list;

template<class T>
class Tree
{
public:
    Tree();
    Tree(T);
    ~Tree();
    
    class TreeNode
    {
    public:
        TreeNode();
        TreeNode(T, TreeNode *);
        ~TreeNode();
        
        T& get_data();
        void set_data(T data);
        
        void add_child(T data);
        void add_children(vector<T*>);
        
        void delete_node();
        void delete_subtree();
        
        typedef list<TreeNode *> NodesList;
        typedef typename list<TreeNode *>::iterator NodesIterator;
        
        TreeNode * get_parent();
        NodesList get_children();
        int count_children();

    private:
        T data;
        TreeNode * parent;
        NodesList children;
    };
    
    TreeNode * get_root();
    
private:
    TreeNode * root;
};

#endif	/* _TREE_H */