#include "LinkedListGraph.h"

int main(int argc, char *argv[])
{
	LinkedListGraph<int> A;
	A.V_insert(2);
	A.V_insert(3);
	A.V_insert(6);
	std::cout << A.length << std::endl;
	A.E_link(6,3,1);
	A.E_link(9,1,2);
	A.E_link(8,2,3);
	A.E_link(1,1,3);
	A.E_link(10,2,1);
	std::cout << A.get_vertex(3).data << std::endl;
	std::cout << A.get_edge(1,2).w << std::endl;
	return 0;
}
