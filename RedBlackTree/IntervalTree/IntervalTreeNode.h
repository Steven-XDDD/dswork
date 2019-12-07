#ifndef __PAISLEYPARK__INTERVALTREENODE__
#define __PAISLEYPARK__INTERVALTREENODE__

#include "BinaryTreeNode.h"

template <class TYPE>
class Interval<TYPE>{
public:
	TYPE low;
	TYPE high;
};

template <class TYPE>
class IntervalTreeNode<TYPE> : public BinaryTreeNode<TYPE> {
public:	
	Interval<TYPE> satelitedata;

	IntervalTreeNode(){};

	IntervalTreeNode(const IntervalTreeNode *_t);

	IntervalTreeNode(IntervalTreeNode *_t);

	IntervalTreeNode(Interval<TYPE> _d);

	~IntervalTreeNode();
};

