#ifndef __PAISLEYPARK__INTERVALTREE__
#define __PAISLEYPARK__INTERVALTREE__

#include "RedBlackTree.h"

template <class TYPE>
class IntervalTree : public RedBlackTree<TYPE>{
public:
	typedef typename RedBlackTree<TYPE>::Node Node;

	IntervalTree(TYPE _x, TYPE _y) : RedBlackTree<TYPE>(_x) {
		this->root->high = _y;
		this->root->low = data;
		this->root->max = _y;
	};

	IntervalTree(){};

	int RightRotate(Node *_x);

	int LeftRotate(Node *_x);

	int insert(Node *_new);

	int insert(TYPE _x, TYPE _y);

	int del(Node *_d);
private:
	int __IT_Max_Fixup(Node *_x);
};

#else
//Do nothing
#endif
