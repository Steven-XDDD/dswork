#include "BinarySearchTree.h"

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::search(TYPE _d) const{
	const Node *x = this->root;
	while(x != this->nil && _d != x->data) {
		if(_d < x->data) {
			x = x->left;	
		}
		else {
			x = x->right;
		}
	}
	if(x != this->nil) {
		return x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::search(TYPE _d) {
	Node *x = this->root;
	while(x != this->nil && _d != x->data) {
		if(_d < x->data) {
			x = x->left;	
		}
		else {
			x = x->right;
		}
	}
	if(x != this->nil) {
		return x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::min() {
	Node *x = this->root;
	if(x != this->nil) {
		while(x->left != this->nil) {
			x = x->left;
		}
	}
	if(x != this->nil) {
		return x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::min() const{
	const Node *x = this->root;
	if(x != this->nil) {
		while(x->left != this->nil) {
			x = x->left;
		}
	}
	if(x != this->nil) {
		return x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::min_value() const{
	const Node *x = this->root;
	if(x == this->nil) {
		std::cerr << "Error! The tree is empty." <<std::endl;\
		return -1;
	}
	while(x->left != this->nil) {
		x = x->left;
	}
	return x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::max() {
	Node *x = this->root;
	if(x != this->nil) {
		while(x->right != this->nil) {
			x = x->right;
		}
	}
	if(x != this->nil) {
		return x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::max() const{
	const Node *x = this->root;
	if(x != this->nil) {
		while(x->right != this->nil) {
			x = x->right;
		}
	}
	if(x != this->nil) {
		return x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::max_value() const{
	const Node *x = this->root;
	if(x == this->nil) {
		std::cerr << "Error! The tree is empty." <<std::endl;\
		return -1;
	}
	while(x->right != this->nil) {
		x = x->right;
	}
	return x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::min(Node *_x) {
	if(_x != this->nil) {
		while(_x->right != this->nil) {
			_x = _x->right;
		}
	}
	if(_x != this->nil) {
		return _x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::min(const Node *_x) const {
	if(_x != this->nil) {
		while(_x->right != this->nil) {
			_x = _x->right;
		}
	}
	if(_x != this->nil) {
		return _x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::min_value(const Node *_x) const {
	if(_x == this->nil) {
		std::cerr << "Error! The tree is empty." <<std::endl;\
		return -1;
	}
	while(_x->left != this->nil) {
		_x = _x->left;
	}
	return _x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::max(Node *_x) {
	if(_x != this->nil) {
		while(_x->right != this->nil) {
			_x = _x->right;
		}
	}
	if(_x != this->nil) {
		return _x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::max(const Node *_x) const {
	if(_x != this->nil) {
		while(_x->right != this->nil) {
			_x = _x->right;
		}
	}
	if(_x != this->nil) {
		return _x;
	}
	else {
		return NULL;
	}
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::max_value(const Node *_x) const {
	if(_x == this->nil) {
		std::cerr << "Error! The tree is empty." <<std::endl;\
		return -1;
	}
	while(_x->right != this->nil) {
		_x = _x->right;
	}
	return _x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::successor(Node *_x) {
	if(_x == this->nil) {
		std::cerr << "Error! The node is a NULL" << std::endl;
		return NULL;
	}
	if(_x->right != this->nil) {
		return min(_x->right);
	}
	Node *y = _x->parent;
	while(y != this->nil && _x == y->right) {
		_x = y;
		y = y->parent;
	}
	if(y != this->nil) {
		return y;
	}
	else {
		return NULL;
	}
}

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::successor(const Node *_x) const {
	if(_x == this->nil) {
		std::cerr << "Error! The node is a NULL" << std::endl;
		return NULL;
	}
	if(_x->right != this->nil) {
		return min(_x->right);
	}
	const Node *y = _x->parent;
	while(y != this->nil && _x == y->right) {
		_x = y;
		y = y->parent;
	}
	if(y != this->nil) {
		return y;
	}
	else {
		return NULL;
	}
}

template <class TYPE>
TYPE BinarySearchTree<TYPE>::succeeding_value(const Node *_x) const {
	if(_x == this->nil) {
		std::cerr << "Error! The node is a NULL" << std::endl;
		std::exit(-1);
	}
	if(_x->right != this->nil) {
		return min_value(_x->right);
	}
	const Node *y = _x->parent;
	while(y != this->nil && _x == y->right) {
		_x = y;
		y = y->parent;
	}
	if(y != this->nil) {
		return y->data;
	}
	else {
		std::cerr << "There is no successor of the maximum node." << std::endl;
		return MIN;
	}
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::predecessor(Node *_x) {
	if(_x == this->nil) {
		std::cerr << "Error! The node is a NULL" << std::endl;
		return NULL;
	}
	if(_x->left != this->nil) {
		return max(_x->left);
	}
	Node *y = _x->parent;
	while(y != this->nil && _x == y->left) {
		_x = y;
		y = y->parent;
	}
	if(y != this->nil) {
		return y;
	}
	else {
		return NULL;
	}
}

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::predecessor(const Node *_x) const {
	if(_x == this->nil) {
		std::cerr << "Error! The node is a NULL" << std::endl;
		return NULL;
	}
	if(_x->left != this->nil) {
		return max(_x->left);
	}
	const Node *y = _x->parent;
	while(y != this->nil && _x == y->left) {
		_x = y;
		y = y->parent;
	}
	if(y != this->nil) {
		return y;
	}
	else {
		return NULL;
	}
}

template <class TYPE>
TYPE BinarySearchTree<TYPE>::preceding_value(const Node *_x) const {
	if(_x == this->nil) {
		std::cerr << "Error! The node is a NULL" << std::endl;
		std::exit(-1);
	}
	if(_x->left != this->nil) {
		return max_value(_x->right);
	}
	const Node *y = _x->parent;
	while(y != this->nil && _x == y->left) {
		_x = y;
		y = y->parent;
	}
	if(y != this->nil) {
		return y->data;
	}
	else {
		std::cerr << "There is no successor of the maximum node." << std::endl;
		return MIN;
	}
};

template <class TYPE>
int BinarySearchTree<TYPE>::insert(Node *_new) {
	Node *x = this->root;
	Node *y = this->nil;
	_new->left = _new->right = this->nil;
	while(x != this->nil) {
		y = x;
		if(_new->data > x->data) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	_new->parent = y;
	if(y == this->nil) {
		this->root = _new;
	}
	else if(_new->data > y->data) {
		y->right = _new;
	}
	else {
		y->left = _new;
	}
	return 0;
};

template <class TYPE>
int BinarySearchTree<TYPE>::insert(TYPE _l, TYPE _h) {
	Node *x = this->root;
	Node *y = this->nil;
	Node *z = new Node(_l, _h);
	z->left = z->right = this->nil;
	while(x != this->nil) {
		y = x;
		if(z->data > x->data) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	z->parent = y;
	if(y == this->nil) {
		this->root = z;
	}
	else if(z->data > y->data) {
		y->right = z;
	}
	else {
		y->left = z;
	}
	return 0;
};

template <class TYPE>
int BinarySearchTree<TYPE>::del(Node *_x) {
	if(_x->left == this->nil) {
		this->transplant(_x, _x->right);
	}	
	else if(_x->right == this->nil) {
		this->transplant(_x, _x->left);
	}
	else {
		Node *y = min(_x->right);
		if(y->parent != _x) {
			this->transplant(y, y->right);
			y->right = _x->right;
			y->right->parent = y;
		}
		this->transplant(_x, y);
		y->left = _x->left;
		y->left->parent = y;
	}
	delete _x;
	return 0;
};
