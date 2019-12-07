#include "IntervalTree.h"

int main(int argc, char *argv[])
{
	IntervalTree<int> A(3, 5);
	A.insert(5, 7);
	A.insert(2, 6);
	A.insert(7, 9);
	A.display();
	std::cout << A.IntervalSearch(8, 10)->data << std::endl;
	return 0;
}
