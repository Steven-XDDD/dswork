/**
 * @file BinarySearchTree.h
 * @brief BinarySearchTree
 * @author XDDDD
 * @version 
 * @date 2019-12-02
 */

#ifndef __PAISLEYPARK__BINARYSEARCHTREE__
#define __PAISLEYPARK__BINARYSEARCHTREE__


#include "BinaryTree.h"

template <class TYPE>
class BinarySearchTree;

template <class TYPE>
class BinarySearchTree : public BinaryTree<TYPE>
{
public:
	typedef typename BinaryTree<TYPE>::Node Node;

	BinarySearchTree(TYPE _val) : BinaryTree<TYPE>(_val) {};

	BinarySearchTree(){};

	const Node *search(TYPE _d) const;

	Node *search(TYPE _d);

	Node *min();

	const Node *min() const;

	TYPE min_value() const;

	Node *min(Node *_x);

	const Node *min(const Node *_x) const;

	TYPE min_value(const Node *_x) const;

	Node *max();

	const Node *max() const;

	TYPe max_value() cosnt;

	Node *max(Node *_x);

	const Node *max(const Node *_x) const;
	
	TYPe max_value(const Node *_x) const;

	Node *successor(Node *_x);

	const Node *successor(const Node *_x) const;

	TYPE succeeding_value(const Node *_x) const;

	Node *predecessor(Node *_x);

	const Node *predecessor(const Node *_x) const;

	TYPE preceding_value(const Node *_x) const;

	int insert(Node *_new);

	int insert(TYPE _d);

	int del(Node *_x);
};

#else
//Do nothing
#endif
