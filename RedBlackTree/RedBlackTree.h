#ifndef __PAISLEYPARK__REDBLACKTREE__
#define __PAISLEYPARK__REDBLACKTREE__

#include "BinarySearchTree.h"

template <class TYPE>
class RedBlackTree;

template <class TYPE>
class RedBlackTree : public BinarySearchtree<TYPE> {
public:
	typedef typename BinarySearchTree<TYPE>::Node Node;

	RedBlackTree(TYPE _val) : BinarySearchTree<TYPE>(_val) {
		this->root->color = Black;
	};

	RedBlackTree(){};

	int insert(Node *_new);

	int insert(TYPE _d);

	int del(Node *_x);
};

#else
//Do nothing.
#endif
