#include "IntervalTree.h"

template <class TYPE>
int IntervalTree<TYPE>::RightRotate(Node *_x) {
	Node *y = _x->left;
	_x->left = y->right;
	if(_x->max > y->max) {
		y->max = _x->max;
	}
	else {
		if(_x->high < _x->right->max) {
				_x->max = _x->right->max;
		}
		else {
			_x->max = _x->high;
		}
		if(_x->max < y->right->max) {
			_x->max = y->right->max;
		}
	}
	if(y->right != this->nil) {
		y->right->parent = _x;
	}
	y->parent = _x->parent;
	if(_x->parent == this->nil) { 
		this->root = y;
	}
	else if(_x == _x->parent->left) {
		_x->parent->left = y;
	}
	else {
		_x->parent->right = y;
	}
	y->right = _x;
	_x->parent = y;
	return 0
};


template <class TYPE>
int IntervalTree<TYPE>::LeftRotate(Node *_x) {
	Node *y = _x->right;
	_x->right = y->left;
	if(_x->max > y->max) {
		y->max = _x->max;
	}
	else {
		if(_x->left != this->nil && _x->high < _x->left->max) {
				_x->max = _x->left->max;
		}
		else {
			_x->max = _x->high;
		}
		if(_x->max < y->left->max) {
			_x->max = y->left->max;
		}
	}
	if(y->left != this->nil) {
		y->left->parent = _x;
	}
	y->parent = _x->parent;
	if(_x->parent == this->nil) {
		this->root = y;
	}
	else if(_x->parent->left == _x) {
		_x->parent->left = y;
	}
	else {
		_x->parent->right = y;
	}
	y->left = _x;
	_x->parent = y;
	return 0;
};

template <class TYPE>
int IntervalTree<TYPE>::insert(Node *_new) {
	Node *x = _new;
	Node *y;
	BinarySearchTree<TYPE>::insert(x);
	if(x->parent->color == BLACK) {
		this->root->color = BLACK;
		IT_Max_Fixup(x);
		return 0;
	}
	while(x->parent->color == RED) {
		if(x->parent == x->parent->parent->left) {
			y = x->parent->parent->right;
			if(y->color == RED) {
				x->parent->color = BLACK;				//case1
				x->parent->parent->color = RED;			//case1
				y->color = BLACK;						//case1
				for(int i = 0; i != 2; i++) {			//case1 fix the max
					if(x->parent->max < x->max) {		//case1 fix the max
						x->parent->max = x->max;		//case1 fix the max
					}									//case1 fix the max
					x = x->parent;						//case1
				}										//case1 
				if(x->parent->color == BLACK) {
					break;
				}
			}
			else  {
				if(x == x->parent->right) {
					x = x->parent;						//case2
					this->LeftRotate(x);				//case2 this version will fix the max
				}
				x->parent->color = BLACK;				//case3
				x->parent->parent->color = RED;			//case3
				this->RightRotate(x->parent->parent);	//case3 this version will fix the max
			}
		}
		else {
			y = x->parent->parent->left;
			if(y->color == RED) {
				y->color = BLACK;						//case1
				x->parent->parent->color = RED;			//case1
				x->parent->color = BLACK;				//case1
				for(int i = 0; i != 2; i++) {			//case1 fix the max
					if(x->parent->max < x->max) {		//case1 fix the max
						x->parent->max = x->max;		//case1 fix the max
					}									//case1 fix the max
					x = x->parent;						//case1 
				}										//case1 
				if(x->parent->color == BLACK) {
					break;
				}
			}
			else {
				if(x == x->parent->left) {
					x = x->parent;						//case2
					this->RightRotate(x);				//case2 this version will fix the max
				}
				x->parent->color = BLACK;				//case3
				x->parent->parent->color = RED;			//case3
				this->LeftRotate(x->parent->parent);	//case3 this version will fix the max
			}
		}
	}
	IT_Max_Fixup(x);
	this->root->color == BLACK;
	return 0;
}; 

template <class TYPE>
int IntervalTree<TYPE>::insert(TYPE _x, TYPE _y) {
	Node *t = new Node(_x, _y);
	insert(t);
 	return 0;
};

template<class TYPE>
int IntervalTree<TYPE>::del(Node *_x) {
	Node *y = _x;
	Node *x;
	Node *z;
	bool original_color_y = y->color;
	if(_x->left == this->nil) {
		x = _x->right;
		this->transplant(_x, _x->right);
	}
	else if(_x->right == this->nil) {
		x = _x->left;
		this->transplant(_x, _x->left);
	} 
	else {
		y = this->min(_x->right);
		original_color_y = y->color;
		x = y->right;
		z = y->right;
		if(y->parent == _x) {
			x->parent = y;
			z->parent = y;
		}
		else {
			this->transplant(y, x);
			while(z != _x && z->parent->max < z->max || z != _x && z->max == y->max) {
				if(z->parent->left->max < z->parent->right->max) {			//fix the max
					z->parent->max = z->parent->right->max;					//fix the max
				}
				else {
					z->parent->max = z->parent->left->max;					//fix the max
				}
			}
			y->right = _x->right;
			y->right->parent = y;
		}
		this->transplant(_x, y);
		if(y->high < _x->max) {
				y->max = _x->max;				//fix the max
			}
		y->left = _x->left;
		y->left->parent = y;
		y->color = _x->color;
	}											//nodes in the y's subtree all have max fixed 
	if(original_color_y == BLACK) {
		while(x != this->root && x->color == BLACK) {
			if(x== x->parent->left) {
				Node *w = x->parent->right;
				if(w->color == RED) {										
					w->color = BLACK;										//case1
					x->parent->color = RED;									//case1
					this->LeftRotate(x->parent);							//case1 this version fixes the max
					w = x->parent->right;									//case1
				}
				if(w->left->color == BLACK && w->right->color == BLACK) {
					w->color = RED;											//case2
					if(x->parent->max < x->max) {
						x->parent->max = x->max;							//case2 fix the max
					}
					x = x->parent;											//case2
				}
				else {
					if(w->right->color == BLACK) {
						w->left->color = BLACK;								//case3
						w->color = RED;										//case3
						this->RightRotate(w);								/*case3	this version fixes the max
																			 ** and this rotate won't influence 
																			 ** the max.
																			 */
						w = x->parent->right;								//case3
					}
					w->color = x->parent->color;							//case4
					x->parent->color = BLACK;								//case4
					w->right->color = BLACK;								//case4
					this->LeftRotate(x->parent);							//case4
					this->__IT_Max_Fixup(x);								//case4 fix the max
					x = this->root;											//case4
				}
			}
			else {
				Node *w = x->parent->left;
				if(w->color == RED) {
					w->color = BLACK;										//case1
					x->parent->color = RED;									//case1
					this->RightRotate(x->parent);							//case1 this version fix the max
					w = x->parent->left;									//case1
				}
				if(w->right->color == BLACK && w->left->color == BLACK) {
					w->color = RED;											//case2
					if(x->parent->max < x->max) {
						x->parent->max = x->max								//case2 fix the max
					}
					x = x->parent;											//case2
				}
				else {
					if(w->left->color == BLACK) {
						w->right->color = BLACK;							//case3
						w->color = RED;										//case3
						this->LeftRotate(w);								/*case3	this version fixes the max
																			 ** and this rotate won't influence 
																			 ** the max.
																			 */
						w = x->parent->left;								//case3
					}
					w->color = x->parent->color;							//case4
					x->parent->color = BLACK;								//case4
					w->left->color = BLACK;									//case4
					this->RightRotate(x->parent);							//case4
					this->__IT_Max_Fixup(x);								//case4 fix the max
					x = this->root;											//case4
				}
			}
		}
		x->color = BLACK;
	}
	delete _x;
	return 0;
}

template <class TYPE>
int IntervalTree::__IT_Max_Fixup(Node *_x) {
	while(_x->parent != this->nil) {
		if(_x->max > _x->parent->max) {
			_x->parent->max = _x->max;
		}
		else {
			break;
		}
		_x->_x->parent;
	}
	return 0;
};
