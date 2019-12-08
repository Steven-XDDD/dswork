#include "IntervalTree.h"

int main(int argc, char *argv[])
{
	IntervalTree<int> A(3, 5);
	A.insert(5, 7);
	A.insert(2, 6);
	A.insert(7, 9);
	A.insert(3,10);
	A.insert(5,8);
	A.del(A.getRoot()->left);
	A.insert(9,15);
	A.insert(3,8);
	A.insert(2,5);	
	A.insert(2,10);
	A.insert(2,16);	
	A.insert(2,12);
	A.display();
	std::cout << A.IntervalSearch(8, 10)->low << ' ' << A.IntervalSearch(8, 10)->high << std::endl;
	return 0;
}
