
#ifndef __PAISLEYPARK__LINKEDLISTGRAPH__
#define __PAISLEYPARK__LINKEDLISTGRAPH__

#include <iostream>
#include <vector>
#include <list>
template <class TYPE>
class vertex {	
	public:
	TYPE data;
	int d;
	vertex *pi;
};

class edge {
public:
	int w;
	int data;
};

template <class TYPE>
class LinkedListGraph {
	typedef vertex<TYPE> vert;
private:
	std::vector<vertex<TYPE> > __V;
	std::vector<std::list<edge> > __E;
public:
	int length = 0;
	int V_insert(TYPE _d);
	int V_initialize();
	int E_link(int _w, int _x, int _y);
	edge get_edge(int _x, int _y);
	vert get_vertex(int _d);
};
#else
//Do nothing
#endif
