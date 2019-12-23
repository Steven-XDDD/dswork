
#ifndef __PAISLEYPARK__LINKEDLISTGRAPH__
#define __PAISLEYPARK__LINKEDLISTGRAPH__

#include <iostream>
#include <vector>
#include <list>
#include <limits>

#define MAX (std::numeric_limits<TYPE>::max())

template <class TYPE>
class vertex {	
public:
	TYPE data;
	int d;
	int pi;
	int p;
	int q;
	bool operator > (const vertex &_a) const {return d < _a.d; };
	bool operator < (const vertex &_a) const {return d > _a.d; };
	bool comp(const vertex &_a, const vertex &_b);
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
	int point = 0;
	int length = 0;
	int V_insert(TYPE _d);
	int V_initialize();
	int E_link(int _w, int _x, int _y);
	edge get_edge(int _x, int _y);
	vert get_vertex(int _d);
	typename std::vector<vertex<TYPE> >::iterator get_Vbegin();
	typename std::vector<vertex<TYPE> >::iterator get_Vend();
	typename std::list<edge>::iterator get_Ebegin(int _d);
	typename std::list<edge>::iterator get_Eend(int _d);
	int fix_Vd(int _a, int _d);
	int fix_Vpi(int _a, int _d);
	int fix_Vq(int _a, int _q);
};
#else
//Do nothing
#endif
