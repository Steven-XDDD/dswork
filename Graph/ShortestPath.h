#ifndef __PAISLEYPARK__SHORTESTPATH__
#define __PAISLEYPARK__SHORTESTPATH__

#include "LinkedListGraph.h"
#include <algorithm>

template <class TYPE>
class ShortestPath : public LinkedListGraph<TYPE> {
private:
	vertex<TYPE> __s;
public:
	std::vector<vertex<TYPE> > Q;
	int insert(LinkedListGraph<TYPE> A, int _d);
	int min_heapify(LinkedListGraph<TYPE> A, int _a);
	int make_heap(LinkedListGraph<TYPE> A);
	vertex<TYPE> extract_min(LinkedListGraph<TYPE> A);
	int Dijkstras(LinkedListGraph<TYPE> A, int _d);
};

#else
//Do nothing
#endif
