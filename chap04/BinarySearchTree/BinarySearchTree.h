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

