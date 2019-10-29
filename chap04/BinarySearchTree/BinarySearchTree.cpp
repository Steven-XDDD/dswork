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

typedef BinaryTree::Node BTNode;

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

BinaryTree::Node::~Node() {
	parent = left = right = NULL;
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

int BinaryTree::reinit(BTNode *_new) {
	__root = _new;
	return 0;
};

int BinaryTree::transplant(BTNode *_u, BTNode *_v) {
	if(_u == NULL) {
		std::cout << "Error. Can not transplant to a null" << std::endl;
		std::exit(-1);
	}
	if(_u->parent == NULL) {
		reinit(_v);
	}
	else if(_u == _u->parent->left) {
		_u->parent->left = _v;
	}
	else {
		_u->parent->right = _v;
	}
	_v->parent = _u->parent;
	release(_u);
	return 0;
};

int BinaryTree::release(BTNode *_x) {
	if(_x != NULL) {
		release(_x->left);
		release(_x->right);
		_x->parent = NULL;
		_x->data = 0;
		delete _x;
	}
	return 0;
};

int BinaryTree::release() {
	release(__root);
	__root = NULL;
	return 0;
};

inline int BinaryTree::__make_space(int _x) const {
	for(int i = 0; i < _x; i++) {
		std::cout << " ";
	}	
	return 0;
};

inline int BinaryTree::__make_both_branch(int _x) const{
	std::cout << "┌";
	for(int i = 0; i < (_x-3)/2 ; i++) 
		std:: cout << "─";
	std:: cout << "┴";
	for(int i = 0; i < (_x-3)/2; i++)
		std::cout << "─";
	std::cout << "┐";
};

inline int BinaryTree::__make_left_branch(int _x)const {
	std::cout << "┌";
	for(int i = 0; i < (_x-3)/2 ; i++)
		std:: cout << "─";
	std:: cout << "┘";
	for(int i = 0; i < (_x-3)/2; i++)
		std::cout << " ";
	std::cout << " ";
};

inline int BinaryTree::__make_right_branch(int _x)const {
	std::cout << " ";
	for(int i = 0; i < (_x-3)/2 ; i++) 
		std:: cout << " ";
	std:: cout << "└";
	for(int i = 0; i < (_x-3)/2; i++)
		std::cout << "─";
	std::cout << "┐";
};

inline int BinaryTree::__pow2(int _x) const {
	return(1 << _x);

};

int BinaryTree::display() const {
	std::queue<Node *> val; /**< For breadth-first tree walk. */
	std::queue<Node *> output;      /**< For print tree. */
	///Children status for a node.
	enum ChildCases {LEFT, RIGHT, BOTH, NONE};
	std::queue<ChildCases> output_cc; /**< The children status of nodes outputing. */
	std::queue<ChildCases> branch_cache; /**< Cache the branches between node and its children. */
	std::queue<Node *> node_cache; /**< Cache th nodes for outputiong. */
	if(__root != NULL)
		val.push(__root);
	else {
		std::cout << "The tree is empty." << std::endl;
		return 0;
	}
	int h = height(); /**< Height of the whole tree. */
	std::vector<int> counter(h, 0); /**< Record the nodes number for each tree layer. */
	int count = 0;     /**< Count the number of outputed nodes. */
	///In this loop, we ues a queue val to apply a breadth-first tree
	///walking and to record the order of nodes outputing by another
	///queue output. In the same time, we also record the children status 
	/// of each outputing node by queue output_cc, and the number of 
	/// nodes to output in each layer of the tree by vector counter.
	while (!val.empty()) {
		bool left_exist = false;
		bool right_exist = false;
		Node *next = val.front();
		val.pop();
		if(next->left != NULL) {
			val.push(next->left);
			left_exist = true;
		}
		if(next->right != NULL) {
			val.push(next->right);
			right_exist = true;
		}
		if(left_exist && right_exist)
			output_cc.push(BOTH);
		else if(left_exist)
			output_cc.push(LEFT);
		else if(right_exist)
			output_cc.push(RIGHT);
		else
			output_cc.push(NONE);
		output.push(next);
		counter[next->depth]++;
	}
	///Because some of the nodes are missing in an imcomplete tree,
	///so we use the variable off to compute the offset of the display position
	///for every outputing node. That means we actually print out a complete tree!
	///In same cases, such as each node only has right child, the complexit of this function 
	/// is 2 to the power of n, which is treeibl. However, this function obvciously is only for
	///small scale debugging usages.
	int off = 0;       /**< Offset of the position to display a node. */
	///In this loop, we actually print the tree by using std::cout.
	///With the branches between nodes and their children.
	while(!output.empty()) {
		Node *next = output.front();
		output.pop();
		///Fill the missing nodes.
		while(off < next->pos) {
			__make_space(__pow2(h - next->depth + 1));
			off++;
		}
		///Offset for centrally print every node.
		__make_space(__pow2(h - next->depth) - 2);
		std::cout << std::setw(3) << std::left << next->data;
		__make_space(__pow2(h - next->depth) - 1);
		count++;
		off++;
		///Recourd the printed node, the children status of these
		///to build the branches between nodes and their chldren.
		node_cache.push(next);
		branch_cache.push(output_cc.front());
		output_cc.pop();
		///The first condition means all nodes in this layer have been printed,
		/// in the next we should print out an enter to start a newline for branches.
		///And the second condition says if we are in the last layer, we
		///don't do it.
		if(count == counter[next->depth] && next->depth != h - 1) {
			count = 0;
			off = 0;
			std::cout << std::endl;
			while(!branch_cache.empty()) {
				ChildCases cc = branch_cache.front();
				branch_cache.pop();
				Node *next = node_cache.front();
				node_cache.pop();
				///Again, we need compute the offset for the branches of those missing nodes.
			while(off < next->pos) {
				__make_space(__pow2(h - next->depth + 1));
				off++;
			}
			/// The offset for centrally print.
			__make_space(__pow2(h - next->depth - 1) - 2 );
			///Pick the different type of the branches.
			if(cc == BOTH)
				__make_both_branch(__pow2(h - next->depth) + 1);
			else if(cc == LEFT)
				__make_left_branch(__pow2(h - next->depth) + 1);
			else if(cc == RIGHT)
				__make_right_branch(__pow2(h - next->depth) + 1);
			else if(cc == NONE)
				__make_space(__pow2(h - next->depth) + 1);
			__make_space(__pow2(h - next->depth - 1) - 2);
			std::cout << "   ";
			off++;
			}
			off = 0;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}

int BinaryTree::updateDepthandPos(BTNode *_x, int _d, int _p) {
	if(_x != NULL) {
		_x->depth = _d;
		_x->pos = _p;
		updateDepthandPos(_x->left, _d + 1, _p * 2);
		updateDepthandPos(_x->right, _d + 1, _p * 2 + 1);
	}
	return 0;
};

int BinaryTree::updateDepthandPos() {
	updateDepthandPos(__root, 0, 0);
	return 0;
};

int BinaryTree::height(BTNode *_x) const {
	if(_x == NULL)
		return 0;
	else 
		return std::max(height(_x->left),height(_x->right)) + 1;
};

int BinaryTree::height() const {
	return height(__root);
};

class BinarySearchTree : public BinaryTree {
public:
	BinarySearchTree(TYPE _val);
	BinarySearchTree(){};
	const Node *search(TYPE _val) const;
	Node *search(TYPE _val);
	Node *max();
	const Node *max() const;
	TYPE max_value() const;
	Node *max(Node *_x);
	const Node *max(const Node *_x) const;
	TYPE max_value(const Node *_x) const;
	Node *min(); 
	const Node *min() const;
	TYPE min_value() const;
	Node *min(Node *_x);
	const Node *min(const Node *_x) const;
	TYPE min_value(const Node *_x) const;
	Node *successor(Node *_x);
	const Node *successor(const Node *_x) const;
	TYPE succeeding_value(const Node *_x) const;
	Node *predecessor(Node *_x);
	const Node *predecessor(const Node *_x)  const;
	TYPE preceding_value(const Node *_x) const;
	int insert(Node *_new);
	int insert(const Node *_new);
	int insert(TYPE _val);
	int del(Node *_x);
};

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
