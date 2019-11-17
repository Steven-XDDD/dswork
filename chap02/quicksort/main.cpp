#include "quicksort.h"
#include <iostream>
#include <ctime>
#include <fstream>
#define MAX 10000000

int main(int argc, char *argv[])
{
	srand(time(NULL));
	std::ofstream mycout("timetest.txt");
	int test_times = 100;
	clock_t start_time, end_time;
	float time;
	int num = 256; 
	std::vector<int> A(256);
	for(int j = 0;j != 11; j++){
		for(int i = num; i != num*2; i++) {
			A.push_back(rand() % (1));
		}
		num = num * 2;
		for(int i = 0; i != 100; i++) {
			std::cout << j << std::endl;
			for(int k = 0; k != num; k++) {
				A[i] = rand() % MAX;
			}
			start_time = clock();
			quicksort(A);
			end_time = clock();
			time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
			mycout << time << std::endl;
		}
		mycout << std::endl;
	}
	mycout.close();
	return 0;
};
