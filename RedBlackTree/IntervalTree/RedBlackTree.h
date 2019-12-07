#ifndef __PAISLEYPARK__REDBLACKTREE__
#define __PAISLEYPARK__REDBLACKTREE__

#include "BinarySearchTree.h"

template <class TYPE>
class RedBlackTree;

template <class TYPE>
class RedBlackTree : public BinarySearchTree<TYPE> {
public:
	typedef typename BinarySearchTree<TYPE>::Node Node;

	RedBlackTree(TYPE _l, TYPE _h) : BinarySearchTree<TYPE>(_l, _h) {
		this->root->color = BLACK;
	};

	RedBlackTree(){};

	int insert(Node *_new);

	int insert(TYPE _l, TYPE _h);

	int del(Node *_x);
};

#else
//Do nothing.
#endif
