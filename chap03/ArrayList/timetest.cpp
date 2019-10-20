#include <iostream>
#include "ArrayList.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#define MAX 10000000

int main(int argc,char *argv[])
{
	srand(time(NULL));
	std::ofstream mycout("timetest.txt");
	int test_times = 50;
	clock_t start_time, end_time;
	float time;
	int num = 256;
	int need_find;
	for(int i = 8; i != 17; i ++) {
		if(num > MAX) {
			num = MAX;
		}
		mycout << "共" << num << "个数据 测" << test_times << "次" << std::endl;
		mycout << "\t";
		for(int j = 0; j != test_times; j ++) {
			need_find = rand() % (num - 0);
			PAISLEYPARK::ArrayList<int> A(num);
			for(int k = 0; k != num; k++) {
				A[k] = rand() % (num - 0);
			}
			A.merge_sort();
			std::cout << need_find <<std::endl;
			start_time = clock();
			std::cout << A.fast_find(need_find) << "\t";
			end_time = clock();
			time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
			mycout << time << "\t";
			start_time = clock();
			std::cout << A.find(need_find) << std::endl;
			end_time = clock();
			time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
			mycout << time << std::endl;
		}
		std::cout << "\tbestsituation" << std::endl;
		mycout << "\t最好情况" << std::endl;
		PAISLEYPARK::ArrayList<int> B(num,1);
		start_time = clock();
		std::cout << B.fast_find(1) << "\t";
		end_time = clock();
		time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
		mycout << time << "\t";
		start_time = clock();
		std::cout << B.find(1) << std::endl;
		end_time = clock();
		time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
		mycout << time << std::endl;

		std::cout << "\tworst situation" << std::endl;
		mycout << "\tfind的最坏情况" << std::endl;
		PAISLEYPARK::ArrayList<int> C(num,3);
		C[1] = 2;
		C[0] = 1;
		start_time = clock();
		std::cout << C.fast_find(2) << "\t";
		end_time = clock();
		time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
		mycout << time << "\t";
		C[num -1] = 4;
		C[1] = 1;
		start_time = clock();
		std::cout << C.find(4) << std::endl;
		end_time = clock();
		time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
		mycout << time << std::endl;

		num = num * 2;
		std::cout << "finished" << 1 << std::endl;
	}
	mycout.close();
	return 0;
}
