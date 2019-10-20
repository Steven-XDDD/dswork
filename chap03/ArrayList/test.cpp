#include <iostream>
#include "ArrayList.h"

int main(int argc, char *argv[])
{
	std::cout << "Test Begin " << std::endl;
	PAISLEYPARK::ArrayList<int> A(8);
	for(int i = 0; i != 8; i++) {
		std::cin >> A[i];
	}
	std::cout << A;
	int t;
	std::cin >> t;
	A.merge_sort();
	std::cout << std::endl;
	std::cout << A.fast_find(t) << std::endl; 
	std::cout << A.find(t) << std::endl;
	return 0;
}
