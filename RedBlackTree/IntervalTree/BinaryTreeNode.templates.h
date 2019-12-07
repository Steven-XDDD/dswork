#include "BinaryTreeNode.h"

template <class TYPE>
BinaryTreeNode<TYPE>::BinaryTreeNode(const BinaryTreeNode *_t) {
	if(_t == NULL) {
		std::cerr << "Error! Can not copy a NULL." << std::endl;
		std::exit(-1);
	}
	data = _t->data;
	max = _t->max;
	low = _t->low;
	high = _t->high;
	parent = left = right = NULL;
};

template <class TYPE>
BinaryTreeNode<TYPE>::BinaryTreeNode(BinaryTreeNode *_t) {
	if(_t == NULL) {
		std::cerr << "Error! Can not copy a NULL." << std::endl;
		std::exit(-1);
	}
	data = _t->data;
	max = _t->max;
	low = _t->low;
	high = _t->high;
	parent = left = right = NULL;
};

template <class TYPE>
BinaryTreeNode<TYPE>::BinaryTreeNode(TYPE _x, TYPE _y) {
	data = _x;
	low = _x;
	high = _y;
	max = _y;
	parent = left = right = NULL;
};

template <class TYPE>
BinaryTreeNode<TYPE>::~BinaryTreeNode() {
	parent = left = right = NULL;	
};
