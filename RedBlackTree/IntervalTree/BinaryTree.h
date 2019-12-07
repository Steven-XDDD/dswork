/**
 * @file BinaryTree.h
 * @brief BinaryTree
 * @author XDDDD
 * @version 
 * @date 2019-12-02
 */

#ifndef __PAISLEYPARK__BINARYTREE__
#define __PAISLEYPARK__BINARYTREE__


#include <limits>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"

#define MIN (std::numeric_limits<TYPE>::min())

#define RESET "\033[0m"
#define RC "\033[31m"	//Red
#define WC "\033[37m"	//White
#define GC "\033[32m"	//Green
#define YC "\033[33m"	//Yellow
#define BC "\033[34m"	//Blue
#define MC "\033[35m"	//Magenta
#define CC "\033[36m"	//Cyan

template <class TYPE>
class BinaryTree;

template <class TYPE>
class BinaryTree
{
public:
	typedef BinaryTreeNode<TYPE> Node;

protected:
	Node *root;
	Node *nil;

private:
	inline int __pow2(int _x) const;

	inline int __make_space(int _x) const;

	inline int __make_both_branch(int _x) const;
	
	inline int __make_left_branch(int _x) const;

	inline int __make_right_branch(int _x) const;

public:
	BinaryTree() {
	nil = new Node;
	nil->color = BLACK;
	nil->max = MIN; 
	root = nil;
	};

	BinaryTree(TYPE _new);

	~BinaryTree();

	const Node *getRoot() const;

	Node *getRoot();

	int setRoot(Node *_r);

	int inorder_walk(const Node *_x) const;

	int inorder_walk() const;

	int release(Node *_x);

	int release();

	int transplant(Node *_u, Node *_v);

	int display();

	int height(const Node *_x) const;

	int height() const;

	int updateDepthandPos();

	int updateDepthandPos(Node *_x, int _d, int _p);

	int insertLeft(Node *_x, TYPE _val);

	int insertRight(Node *_x, TYPE _val);

	int RightRotate(Node *_x);

	int LeftRotate(Node *_x);
};

#else
//Do nothing
#endif

