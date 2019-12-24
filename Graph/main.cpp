#include "ShortestPath.h"

int main(int argc, char *argv[])
{
	int a = 10;
	ShortestPath<int> B;
	LinkedListGraph<int> A;
	A.V_insert(9);
	A.V_insert(3);
	A.V_insert(6);
	A.V_insert(5);
	A.V_insert(8);
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
	B.Dijkstras(A, 1);
	std::cout << A.get_vertex(5).d << std::endl;
	std::cout << A.get_vertex(1).d << std::endl;
	std::cout << A.get_vertex(2).d << std::endl;
	std::cout << A.get_vertex(3).d << std::endl;
	std::cout << A.get_vertex(4).d << std::endl;
	std::cout << A.get_vertex(5).d << std::endl;
	std::cout << A.get_edge(1,2).w << std::endl;
	return 0;
}
