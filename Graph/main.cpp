#include "ShortestPath.h"
//#include <algorithm>

int main(int argc, char *argv[])
{
	int a = 10;
//	std::vector<vertex<int> > Q;
	ShortestPath<int> B;
	LinkedListGraph<int> A;
	//std::vector<vertex<int> >::iterator itr = A.get_Vbegin();
	A.V_insert(9);
	A.V_insert(3);
	A.V_insert(6);
	A.V_insert(5);
	A.V_insert(8);
/*	std::vector<vertex<int> >::iterator itr = A.get_Vbegin();
	while(itr != A.get_Vend()) {
		(*itr).d = a;
		Q.push_back(*itr);
		itr++;
		a++;
	}
	A.fix_Vd(1,3);
	std::cout << A.get_vertex(1).p << std::endl;
	make_heap(Q.begin(), Q.end());
*/	
	
//	std::cout << Q[0].d << std::endl;
	std::cout << A.length << std::endl;
	A.E_link(6,3,1);
	A.E_link(9,1,2);
	A.E_link(8,2,3);
	A.E_link(1,1,3);
	A.E_link(10,2,1);
	A.E_link(4,2,5);
	A.E_link(6,5,4);
	A.E_link(5,4,3);
	A.E_link(3,5,3);
	A.E_link(10,1,4);
	std::cout << A.get_vertex(5).d << std::endl;
	A.V_initialize();
	B.Dijkstras(A, 1);
	std::cout << A.get_vertex(5).d << std::endl;
/*	vertex<int> u;
	std::vector<vertex<int> > &Q;
	typename std::vector<vertex<int> >::iterator itr = A.get_Vbegin();
	for(;itr != A.get_Vend(); itr++) {
		if(itr - A.get_Vbegin() + 1 == 1) {
			(*itr).d = 0;
		}
		vertex<int> &a = (*itr); 
		Q.push_back(a);
	}
	make_heap(Q.begin(), Q.end());
	while(!Q.empty()) {
		pop_heap(Q.begin(), Q.end());
		u = *(Q.end() - 1);
		Q.erase(Q.end() - 1 );
		std::list<edge>::iterator itre = A.get_Ebegin(u.p);
		for(;itre != A.get_Eend(u.p); itre++) {
			if(A.get_vertex((*itre).data).d > u.d + (*itre).w) {	
				A.fix_Vd((*itre).data, u.d + (*itre).w);
				A.fix_Vpi((*itre).data, u.p);
//				A.get_vertex((*itre).data).d = u.d + (*itre).w;		
//				A.get_vertex((*itre).data).pi = u.p;
				}
		}
	}*/
	std::cout << A.get_vertex(1).d << std::endl;
	std::cout << A.get_vertex(2).d << std::endl;
	std::cout << A.get_vertex(3).d << std::endl;
	std::cout << A.get_vertex(4).d << std::endl;
	std::cout << A.get_vertex(5).d << std::endl;
//	std::cout << A.get_vertex(A.get_vertex(5).pi).d <<std::endl;
	std::cout << A.get_edge(1,2).w << std::endl;
	
	return 0;
}
