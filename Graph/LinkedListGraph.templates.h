#include "LinkedListGraph.h"

template <class TYPE>
int LinkedListGraph<TYPE>::V_insert(TYPE _d) {
	this->length = this->length + 1;
	vert a;
	std::list<edge> b;
	a.data = _d;
	a.d = 0;
	a.pi = NULL;
	__V.push_back(a);
	__E.push_back(b);
	return 0;
};

template <class TYPE>
int LinkedListGraph<TYPE>::V_initialize() {
	typename std::vector<vert>::iterator itr = __V.begin();
	for(; itr != __V.end(); itr++) {
		(*itr).pi = NULL;
	}
	return 0;
};

template <class TYPE>
int LinkedListGraph<TYPE>::E_link(int _w, int _y, int _x) {
	edge a;
	a.w = _w;
	a.data = _x;
	std::vector<std::list<edge> >::iterator itr = __E.begin();
	itr = itr + _y - 1;
	(*itr).push_back(a);
	return 0;
};

template <class TYPE>
edge LinkedListGraph<TYPE>::get_edge(int _x, int _y) {
	std::vector<std::list<edge> >::iterator itrv = __E.begin();
	itrv = itrv + _x - 1;
	std::list<edge>::iterator itre = (*itrv).begin();
	while(itre != (*itrv).end()) {
		if((*itre).data == _y) {
			return (*itre);
		}
		itre++;
	}
	std::cerr << "no such edge" << std::endl;
	std::exit(-1);
};

template <class TYPE>
vertex<TYPE> LinkedListGraph<TYPE>::get_vertex(int _d) {
	typename std::vector<vert>::iterator itrv = __V.begin();
	if(itrv + _d > __V.end()) {
		std::cerr << "no such vertex" << std::endl;
		std::exit(-1);
	}
	else {
		return (*(itrv + _d - 1));
	}
};
