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
	};
	const Node *getroot();
	int inorder_walk();
	int inorder_walk(Node *_x);
	BinaryTree(){};
	BinaryTree(TYPE _val);

private:
	Node *__root = NULL;
};

class BinarySearchTree : public BinaryTree {
public:
	BinarySearchTree(TYPE _val);
	BinarySearchTree(){};
	Node *search(Node *_x, TYPE _val);
};

typedef BinaryTree::Node BTNode;
typedef BinarySearchTree::Node BSTNode;

const BTNode *BinaryTree::getroot() {
	return __root;	
};

int BinaryTree::inorder_walk(Node *_x) {
	if(_x != NULL) {
	inorder_walk(_x->left);
	std::cout << _x->data << " ";
	inorder_walk(_x->right);
	}
	return 0;
};


int BinaryTree::inorder_walk() {
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

BinarySearchTree::BinarySearchTree(TYPE _val) : BinaryTree(_val) {};

BSTNode *BinarySearchTree::search(Node *_x, TYPE _val) {
	if(_x == NULL || _x->data == _val) {
		return _x;
	}
	else if(_val < _x->data)
		return search(_x->left, _val);
	else 
		return search(_x->right, _val); 
};

int main(int argc, char *argv[])
{
	BSTNode *r = new BSTNode;
	r->data = 6;
	r->parent = NULL;
	r->right = new BSTNode;
	r->left = new BSTNode;
	r->right->data = 7;
	r->left->data = 5;
	r->right->parent = r;
	r->left->parent = r;
	r->left->left = new BSTNode;
	r->left->left->parent = r->left;
	r->left->right = new BSTNode;
	r->left->right->parent = r->left;
	r->left->left->data = 2;
	r->left->left->left = NULL;
	r->left->left->right = NULL;
	r->left->right->data = 5;
	r->left->right->left = NULL;
	r->left->right->right = NULL;
	r->right->right = new BSTNode;
	r->right->right->parent = r->right;
	r->right->right->left = NULL;
	r->right->right->right = NULL;
	r->right->right->data = 8;
	r->right->left = NULL;
	BinarySearchTree A;
	A.inorder_walk(r);
	std::cout << std::endl;
	BSTNode *t = A.search(r,8);
	if(t != NULL)
		std::cout << t->data <<std::endl;
	else 
		std::cout << "NULL." << std::endl;
	return 0;
}
