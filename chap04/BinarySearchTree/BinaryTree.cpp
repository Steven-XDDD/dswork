#include "BinaryTree.h"

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
