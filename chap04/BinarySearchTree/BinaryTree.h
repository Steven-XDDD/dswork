#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <vector>

typedef int TYPE;

#define MIN (std::numeric_limits<TYPE>::min())

class BinaryTree {
public:
	class Node {
	public:
		Node *parent;
		Node *left;
		Node *right;
		TYPE data;
		int depth;
		int pos;
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
	BinaryTree(){
	__root = NULL;
	};
	BinaryTree(TYPE _val);
	int reinit(Node *_new);
	int transplant(Node *_u, Node *_v);
	int release();
	int release(Node *_x);
	int display() const;
	int height(Node *_x) const;
	int height() const;
	int updateDepthandPos();
	int updateDepthandPos(Node *_x, int _d, int _p);

private:
	Node *__root = NULL;
	inline int __pow2(int _x) const;
	inline int __make_space(int _x) const;
	inline int __make_both_branch(int _x) const;
	inline int __make_left_branch(int _x) const;
	inline int __make_right_branch(int _x) const;
};
