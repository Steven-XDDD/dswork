#include "ShortestPath.h"

template <class TYPE>
int ShortestPath<TYPE>::insert(LinkedListGraph<TYPE> A, int _d){
	int a = 1;
	typename std::vector<vertex<TYPE> >::iterator itr = A.get_Vbegin();
	for(;itr != A.get_Vend(); itr++) {
		if(itr - A.get_Vbegin() + 1 == _d) {
			(*itr).d = 0;
		}
		Q.push_back((*itr));
		(*itr).q = a;
		a++;
	}
	return 0;
};

template <class TYPE>
int ShortestPath<TYPE>::min_heapify(LinkedListGraph<TYPE> A, int _a) {
	int l = 2*_a;
	int r = 2*_a + 1;
	int smallest;
	vertex<TYPE> t;
	if(l <= Q.size() && Q[r - 1].d < Q[_a - 1].d) {
		smallest = l;
	}
	else {
		smallest = r;
	}
	if(r <= Q.size() && Q[r - 1].d < Q[smallest - 1].d) {
		smallest = r;
	}
	if(smallest != _a) {
		t = Q[_a - 1];
		Q[_a - 1] = Q[smallest - 1];
		Q[smallest - 1] = Q[_a - 1];
		A.fix_Vq(Q[_a - 1].p, _a);
		A.fix_Vq(Q[smallest - 1].p, smallest);
		min_heapify(A, smallest);
	}
};

template <class TYPE>
int ShortestPath<TYPE>::make_heap(LinkedListGraph<TYPE> A) {
	int l = Q.size();
	for(int i = l / 2; i != 0; i--) {
		min_heapify(A, i);
	}
};

template <class TYPE>
vertex<TYPE> ShortestPath<TYPE>::extract_min(LinkedListGraph<TYPE> A) {
	vertex<TYPE> t;
	if(Q.size() != 0) {
	vertex<TYPE> t;
	*Q.begin() = *(Q.end() - 1);
	*(Q.end() - 1) = t;
	A.fix_Vq(Q[0].p, 1);
	A.fix_Vq(Q[Q.size() - 1].p, Q.size());
	}
	t = *(Q.end() - 1);
	Q.erase(Q.end() - 1);
	min_heapify(A, 1);
	return t;
}

template <class TYPE>
int ShortestPath<TYPE>::Dijkstras(LinkedListGraph<TYPE> A, int _d) {
	A.V_initialize();
	this->__s = A.get_vertex(_d);
	vertex<TYPE> u;
	insert(A, _d);
	make_heap(A);
/*	std::vector<vertex<TYPE> > Q;
	typename std::vector<vertex<TYPE> >::iterator itr = A.get_Vbegin();
	for(;itr != A.get_Vend(); itr++) {
		if(itr - A.get_Vbegin() + 1 == _d) {
			(*itr).d = 0;
		}
		Q.push_back((*itr));
	}
	make_heap(Q.begin(), Q.end());*/
	while(!Q.empty()) {
		u = extract_min(A);
		std::list<edge>::iterator itre = A.get_Ebegin(u.p);
		for(;itre != A.get_Eend(u.p); itre++) {
			if(A.get_vertex((*itre).data).d > u.d + (*itre).w) {
				A.fix_Vd((*itre).data, u.d + (*itre).w);
				A.fix_Vpi((*itre).data, u.p);
				Q[A.get_vertex((*itre).data).q - 1].d = u.d + (*itre).w;
				Q[A.get_vertex((*itre).data).q - 1].pi = u.p;

//				A.get_vertex((*itre).data).d = u.d + (*itre).w;		
//				A.get_vertex((*itre).data).pi = u.p;
				}
		}
	}
	return 0;
}
