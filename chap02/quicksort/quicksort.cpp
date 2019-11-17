#include "quicksort.h"

int Hoare_partition(std::vector<int> &A,int _p,int _q) {
	srand(time(NULL));
	int t = rand() % (_q - _p + 1) + _p; 
	int x = A[t];
	A[t] = A[_p];
	A[_p] = x;
	int i = _p;
	int j = _q + 1;
	while(1) {
		do {
			j = j - 1;	
		} while(A[j] > x);
		do {
			i = i + 1;
		} while(A[i] < x && i != _q);
		if(i < j ) {
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
		else {
			t = A[j];
			A[j] = A[_p];
			A[_p] = t;
			return j;
		}
	}
};

int insert_sort(std::vector<int> &A, int _p,int _q) {
	int t;
	for(int i = _p; i < _q; i++) {
		for(int j = i; j < _q + 1; j++) {
			if(A[j] < A[i]) {
				t = A[j];
				A[j] = A[i];
				A[i] = t;
			}
		}
	}
	return 0;
};

int quick_sort(std::vector<int> &A, int _p,int _q) {
	int r = Hoare_partition(A, _p, _q);
	if(r - _p > 3)
		quick_sort(A, _p, r - 1);
	else 
		insert_sort(A, _p, r - 1);
	if(_q - r > 3)
		quick_sort(A, r + 1, _q);
	else 
		insert_sort(A, r + 1, _q);
	return 0;
}; 

int quicksort(std::vector<int> &A) {
	int n = (int)A.size();
	if(n > 3)
		quick_sort(A, 0, n - 1);
	else
		insert_sort(A, 0, n - 1);
	return 0;
};
