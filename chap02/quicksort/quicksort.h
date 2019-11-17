/**
 * @file quicksort.h
 * @brief quicksort algorithm for data structure 
 * @author XDDDD 
 * @date 2019-11-17
 */

#ifndef __PAISLEYPARK__QUICKSORT__
#define __PAISLEYPARK__QUICKSORT__

#include <iostream>
#include <vector>
#include <ctime>

/**
 * @brief Sort the int vector A by using quicksort
 *
 * @param A
 *
 * @return 
 */
int quicksort(std::vector<int> &A); 

/**
 * @brief Partition part of the int vector A by using Hoare's algorithm
 *
 * @param A
 * @param _p
 * @param _q
 *
 * @return 
 */
int Hoare_partition(std::vector<int> &A,int _p,int _q);

/**
 * @brief Sort part of the int vector A by using insertsort 
 *		  if the part has less than three number
 *
 * @param A
 * @param _p
 * @param _q
 *
 * @return 
 */
int insert_sort(std::vector<int> &A, int _p,int _q);

/**
 * @brief Sort part of the int vector A by using quicksort
 *
 * @param A
 * @param _p
 * @param _q
 *
 * @return 
 */
int quick_sort(std::vector<int> &A, int _p,int _q);

#else
//Do nothing

#endif
