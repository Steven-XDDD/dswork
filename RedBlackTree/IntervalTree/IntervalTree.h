#ifndef __PAISLEYPARK__INTERVALTREE__
#define __PAISLEYPARK__INTERVALTREE__

#include "RedBlackTree.h"

template <class TYPE>
class IntervalTree : public RedBlackTree<TYPE>{
public:
	typedef typename RedBlackTree<TYPE>::Node Node;

	IntervalTree(TYPE _x, TYPE _y) : RedBlackTree<TYPE>(_x) {
		this->root->high = _y;
		this->root->low = data;
		this->root->max = _y;
	};

	/**
	 * Default constructor.
	 */
	IntervalTree(){};

	/**
	 * @brief Right rotation for IntervalTree, fix the max. 
	 *
	 * @param _x The pivot
	 *
	 * @return 
	 */
	int RightRotate(Node *_x);

	/**
	 * @brief Left rotation for IntervalTree, fix the max. 
	 *
	 * @param _x The pivot
	 *
	 * @return 
	 */
	int LeftRotate(Node *_x);

	/**
	 * @brief Insert for IntervalTree, fix the max.
	 *
	 * @param _new The new node to insert.
	 *
	 * @return 
	 */
	int insert(Node *_new);

	/**
	 * @brief Insert for IntervalTree, fix the max.
	 *
	 * @param _x The low number of the node to insert
	 * @param _y The high number of the node to insert
	 *
	 * @return 
	 */
	int insert(TYPE _x, TYPE _y);

	/**
	 * @brief Deletion for IntervalTree, fix the max.
	 *
	 * @param _d The node to delete.
	 *
	 * @return 
	 */
	int del(Node *_d);

	/**
	 * @brief Find the node that overlap with the given interval.
	 *
	 * @param _x The low number of the given interval. 
	 * @param _y The high number of the given interval.
	 *
	 * @return 
	 */
	Node *IntervalSearch(TYPE _x, TYPE *_y);
private:
	/**
	 * @brief Fixup the max in the tree.
	 *
	 * @param _x Start the fixup from node _x.
	 *
	 * @return 
	 */
	int __IT_Max_Fixup(Node *_x);
};

#else
//Do nothing
#endif
