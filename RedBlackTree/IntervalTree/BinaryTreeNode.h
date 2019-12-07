/**
 * @file BinaryTreeNode.h
 * @brief A node defination for binary trees.
 * @author XDDDD
 * @version 
 * @date 2019-12-02
 */


#ifndef __PAISLEYPARK__BINARYTREENODE__
#define __PAISLEYPARK__BINARYTREENODE__


#include <iostream>
#include <cstdlib>
#define BLACK false
#define RED true

template <class TYPE>
class BinaryTreeNode
{
public:
	TYPE data;					//Satellite data
	BinaryTreeNode *left;		//Left child
	BinaryTreeNode *right;		//Right child
	BinaryTreeNode *parent;		//Parent
	int depth;					//Depth of the node	
	int pos;					/**Location in the current layer
								 *	in the full binary tree */
	bool color = RED;
	TYPE low;					//for use of the intervaltree nodes
	TYPE high;					//for use of the intervaltree nodes
	TYPE max;					//for use of the intervaltree nodes

	/**
	 * @brief Default constructor
	 */
	BinaryTreeNode(){};

	/**
	 * @brief Copy a node from teh given const address
	 *
	 * @param _t The const address point to a node(can not be null)
	 */
	BinaryTreeNode(const BinaryTreeNode *_t);

	BinaryTreeNode(BinaryTreeNode *_t);

	BinaryTreeNode(TYPE _x, TYPE _y);

	~BinaryTreeNode();
};

#else
//Do nothing
#endif
