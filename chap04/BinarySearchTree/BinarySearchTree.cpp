#include "BinarySearchTree.h"

typedef BinarySearchTree::Node BSTNode;

BinarySearchTree::BinarySearchTree(TYPE _val) : BinaryTree(_val) {};

const BSTNode *BinarySearchTree::search(TYPE _val) const{
	const BSTNode *x = getroot();
	if(x == NULL || x->data == _val) {
		return x;
	}
	while(x != NULL) {
		if(x->data == _val) {
			break;
		}
		else if(x->data < _val) {
			x = x->right; 
		}
		else {
			x = x->left;
		}
	}
	if(x != NULL)
		return x;
	else
		std::cout << "No such node" << std::endl;
	return NULL;
};

BSTNode *BinarySearchTree::search(TYPE _val) {
	BSTNode *x = getroot();
	if(x == NULL || x->data == _val) {
		return x;
	}
	while(x != NULL) {
		if(x->data == _val) {
			break;
		}
		else if(x->data < _val) {
			x = x->right; 
		}
		else {
			x = x->left;
		}
	}
	if(x != NULL)
		return x;
	else
		std::cout << "No such node" << std::endl;
	return NULL;
};

BSTNode *BinarySearchTree::max() {
	BSTNode *x = getroot();
	if(x == NULL) {
		std::cout << "Error. This Tree has no node" << std::endl;
	}
	while(x->right != NULL) {
		x = x->right;
	}
	return x;
}

const BSTNode *BinarySearchTree::max() const {
	const BSTNode *x = getroot();
	if(x == NULL) {
		std::cout << "Error. This Tree has no node" << std::endl;
	}
	while(x->right != NULL) {
		x = x->right;
	}
	return x;
}

TYPE BinarySearchTree::max_value() const{
	const BSTNode *x = getroot();
	if(x == NULL) {
	std::cout << "Error.The Tree is NULL" << std::endl;
	}
	while(x->right != NULL) {
		x = x->right;
	}	
	return x->data;
};

BSTNode *BinarySearchTree::max(BSTNode *_x) {
	if(_x == NULL) {
		std::cout << "Error. There is no such node" << std::endl;
	}	
	while(_x->right != NULL) {
		_x = _x->right; 
	}
	return _x;
};

const BSTNode *BinarySearchTree::max(const BSTNode *_x) const{
	if(_x == NULL) {
		std::cout << "Error. There is no such node" << std::endl;
	}	
	while(_x->right != NULL) {
		_x = _x->right; 
	}
	return _x;
};

TYPE BinarySearchTree::max_value(const BSTNode *_x) const{
	if(_x == NULL) {
		std::cout << "Error. There is no such node" << std::endl;
	}
	while(_x->right != NULL) {
		_x = _x->right; 
	}
	return _x->data;
};

BSTNode *BinarySearchTree::min() {
	BSTNode *x = getroot();
	if(x == NULL) {
		std::cout << "Error.The Tree is NULL" << std::endl;
	}
	while(x->left != NULL) {
		x = x->left;
	}	
	return x;
}; 

const BSTNode *BinarySearchTree::min() const{
	const BSTNode *x = getroot();
	if(x == NULL) {
		std::cout << "Error.The Tree is NULL" << std::endl;
	}
	while(x->left != NULL) {
		x = x->left;
	}	
	return x;
};
	
TYPE BinarySearchTree::min_value() const{
	const BSTNode *x = getroot();
	if(x == NULL) {
	std::cout << "Error.The Tree is NULL" << std::endl;
	}
	while(x->left != NULL) {
		x = x->left;
	}	
	return x->data;
};

BSTNode *BinarySearchTree::min(BSTNode *_x) {
	if(_x == NULL) {
		std::cout << "Error. There is no such node" << std::endl;
	}	
	while(_x->left != NULL) {
		_x = _x->left; 
	}
	return _x;
};

const BSTNode *BinarySearchTree::min(const BSTNode *_x) const{
	if(_x == NULL) {
		std::cout << "Error. There is no such node" << std::endl;
	}	
	while(_x->left != NULL) {
		_x = _x->left; 
	}
	return _x;
};

TYPE BinarySearchTree::min_value(const BSTNode *_x) const{
	if(_x == NULL) {
		std::cout << "Error. There is no such node" << std::endl;
	}
	while(_x->left != NULL) {
		_x = _x->left; 
	}
	return _x->data;
};

BSTNode *BinarySearchTree::successor(BSTNode *_x) {
	if(_x == NULL) {
		std::cout << "Error. The node is NULL" << std::endl;
		return NULL;
	}
	if(_x->right != NULL) {
		return min(_x->right);
	}
	BSTNode *y = _x->parent;
	while(y != NULL && _x == y->right) {
		_x = y;
		y = _x->parent;
	}
	return y;
};

const BSTNode *BinarySearchTree::successor(const BSTNode *_x) const{
	if(_x == NULL) {
		std::cout << "Error. The node is NULL" << std::endl;
		return NULL;
	}
	if(_x->right != NULL) {
		return min(_x->right);
	}
	const BSTNode *y = _x->parent;
	while(y != NULL && _x == y->right) {
		_x = y;
		y = _x->parent;
	}
	return y;
};

TYPE BinarySearchTree::succeeding_value(const BSTNode *_x) const {
	if(_x == NULL) {
		std::cout << "Error. The node is NULL" << std::endl;
		std::exit(-1);
	}
	if(_x->right != NULL) {
		return min_value(_x->right);
	}
	const BSTNode *y = _x->parent;
	while(y != NULL && _x == y->right) {
		_x = y;
		y = _x->parent;
	}
	if(y == NULL) {
		std::cerr << "There is no successor of the maximum node." << std::endl;
		return MIN;
	}
	else
	return y->data;
};

BSTNode *BinarySearchTree::predecessor(BSTNode *_x) {
	if(_x == NULL) {
		std::cout << "Error. The node is NULL" << std::endl;
		return NULL;
	}
	if(_x->left != NULL) {
		return max(_x->left);
	}
	BSTNode *y = _x->parent;
	while(y != NULL && _x == y->left) {
		_x = y;
		y = _x->parent;
	}
	return y;
};

const BSTNode *BinarySearchTree::predecessor(const BSTNode *_x) const{
	if(_x == NULL) {
		std::cout << "Error. The node is NULL" << std::endl;
		return NULL;
	}
	if(_x->left != NULL) {
		return min(_x->left);
	}
	const BSTNode *y = _x->parent;
	while(y != NULL && _x == y->left) {
		_x = y;
		y = _x->parent;
	}
	return y;
};
TYPE BinarySearchTree::preceding_value(const BSTNode *_x) const {
	if(_x == NULL) {
		std::cout << "Error. The node is NULL" << std::endl;
		std::exit(-1);
	}
	if(_x->left != NULL) {
		return max_value(_x->left);
	}
	const BSTNode *y = _x->parent;
	while(y != NULL && _x == y->left) {
		_x = y;
		y = _x->parent;
	}
	if(y == NULL) {
		std::cerr << "There is no predecessor of the minimum node." << std::endl;
	}
	else
	return y->data;
};
int BinarySearchTree::insert(BSTNode *_new) {
	Node *x = getroot();
	Node *y = NULL;
	_new->left = _new->right = NULL;
	while(x != NULL) {
		y = x;
		if(_new->data > x->data) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	_new->parent = y;
	if(y == NULL) {
		reinit(_new);
	}
	else if(y->data > _new->data) {
		y->right = _new;
	}
	else {
		y->left = _new;
	}
	return 0;
};	

int BinarySearchTree::del(BSTNode *_x) {
	if(_x->left == NULL && _x->right == NULL) {
		transplant(_x,NULL);
	}
	else if(_x->left == NULL && _x->right != NULL) {
		transplant(_x,_x->left);
	}
	else if(_x->left != NULL && _x->right == NULL) {
		transplant(_x, _x->right);
	}
	else {
		BSTNode *y = successor(_x);
		if(y->parent != _x) {
			transplant(y, y->right); 
			y->right = _x->right;
			y->right->parent = y;
		}
		else {
			y->left = _x->left;
			y->left->parent = y;
		}
	}
	_x->left = _x->right = _x->parent = NULL;
	_x->data = 0;
	delete _x;
};

int BinarySearchTree::insert(const BSTNode *_new) {
	BSTNode *x = getroot();
	BSTNode *y = NULL;
	BSTNode *z = new Node(_new);
	z->left = z->right = NULL;
	while(x != NULL) {
		y = x;
		if(z->data > x->data) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	z->parent = y;
	if(y == NULL) {
		reinit(z);
	}
	else if(y->data > z->data) {
		y->right = z;
	}
	else {
		y->left = z;
	}
	return 0;
}

int BinarySearchTree::insert(TYPE _val) {
	BSTNode *x = getroot();
	BSTNode *y = NULL;
	BSTNode *_new = new Node(_val);
	_new->left = _new->right = NULL;
	while(x != NULL) {
		y = x;
		if(_new->data > x->data) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	_new->parent = y;
	if(y == NULL) {
		reinit(_new);
	}
	else if(_new->data > y->data) {
		y->right = _new;
	}
	else {
		y->left = _new;
	}
	return 0;
};

int main(int argc, char *argv[])
{
	BinarySearchTree A;
	A.insert(6);
	A.insert(7);
	A.insert(5);
	A.insert(2);
	A.insert(5);
	A.insert(8);
	std::cout << std::endl;
	BSTNode *r = A.getroot();
	A.inorder_walk();
	std::cout << 123;
	A.__make_space(5);
	std::cout << 123 << std::endl;
	
	A.updateDepthandPos();
	A.display();
	std::cout << A.search(2)->parent->data << std::endl;
	std::cout << A.min()->data << std::endl;
	std::cout << A.min_value() << std::endl;
	A.release(r->left);
	A.release();
	return 0;
}
