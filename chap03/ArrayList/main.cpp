#include <iostream>
#include "ArrayList.h"

int main(int argc, char *argv[])
{
	std::cout << "begin to test..." << std::endl;
	PAISLEYPARK::ArrayList<int> A(5,3);
	A.printArrayList();
	std::cout << A.find(3) << std::endl;
	for(int i = 0; i != 5; i++) {
		A[i] = i;
	}
	for(int i = 0; i != 5; i ++) {
		std::cout << A[i] << "\t";
	}
	std::cout << std::endl;

	std::cout << "Test << :" << A << std::endl;
	std::cout << A.find(3) << std::endl;
	PAISLEYPARK::ArrayList<int> B(1);
	B[0] = 5;
//	B[1] = 1;
//	B[2] = 4;
//	B[3] = 2;
//	B[4] = 3;
	B.merge_sort();
	
	return 0;
}
