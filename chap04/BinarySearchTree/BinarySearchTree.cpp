#include <iostream>

typedef int TYPE;

class BinaryTree {
public:
	class Node {
	public:
		Node *parent;
		Node *left;
		Node *right;
		TYPE data;
		Node(){};
		Node(Node *_t);
		Node(const Node *_t);
		Node(TYPE _v);
		~Node();
	};
	const Node *getroot() const;
	Node *getroot();
	int inorder_walk() const;
	int inorder_walk(const Node *_x) const;
	BinaryTree(){};
	BinaryTree(TYPE _val);
	int reinit(Node *_new);

private:
	Node *__root = NULL;
};

class BinarySearchTree : public BinaryTree {
public:
	BinarySearchTree(TYPE _val);
	BinarySearchTree(){};
	Node *search(TYPE _val);
	Node *max();
	const Node *max() const;
	TYPE max_value() const;
	Node *min(); 
	const Node *min() const;
	TYPE min_value() const;
	int insert(Node *_new);
	int insert(const Node *_new);
	int insert(TYPE _val);
};

typedef BinaryTree::Node BTNode;
typedef BinarySearchTree::Node BSTNode;

const BTNode *BinaryTree::getroot() const{
	return (dynamic_cast<const Node *>(__root));	
};

BTNode *BinaryTree::getroot() {
	return __root;
};

BinaryTree::Node::Node(const BTNode *_t) {
	if(_t = NULL) {
		std::cerr << "Error! Can not copy a NULL" << std::endl;
		std::exit(-1);
	}
	data = _t->data;
	parent = left = right = NULL;
};

BinaryTree::Node::Node(BTNode *_t) {
	if(_t = NULL) {
		std::cerr << "Error! Can not copy a NULL" << std::endl;
		std::exit(-1);
	}
	data = _t->data;
	parent = left = right = NULL;
};

BinaryTree::Node::Node(TYPE _v) {
	data = _v;
	parent = right = left = NULL;
};

int BinaryTree::inorder_walk(const Node *_x) const{
	if(_x != NULL) {
	inorder_walk(_x->left);
	std::cout << _x->data << " ";
	inorder_walk(_x->right);
	}
	return 0;
};


int BinaryTree::inorder_walk() const{
	BinaryTree::inorder_walk(__root);
	std::cout << std::endl;
	return 0;
};

BinaryTree::BinaryTree(TYPE _val) {
	__root = new Node;
	__root->left = NULL;
	__root->right = NULL;
	__root->parent = NULL;
	__root->data = _val;
};

int BinaryTree::reinit(Node *_new) {
	__root = _new;
	return 0;
};

BinarySearchTree::BinarySearchTree(TYPE _val) : BinaryTree(_val) {};

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
}	
	

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
	A.inorder_walk();
	std::cout << A.search(2)->parent->data << std::endl;
	std::cout << A.min()->data << std::endl;
	std::cout << A.min_value() << std::endl;
	return 0;
}
