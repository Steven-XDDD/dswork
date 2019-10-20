/**
 * @file ArrayList.h
 *
 * @brief An implementation of the static ADT List 
 *	just a student homework
 *
 * @author XDDDD
 * @date 2019-09-20
 */

#ifndef __PAISLEYPARK__ArrayList__
#define __PAISLEYPARK__ArrayList__

#include <iostream>
#include <limits>
#include <cstdlib>

namespace PAISLEYPARK{
	template <typename TYPE> class ArrayList;

	/**
	 * @brief To print out the content in the streams
	 *
	 * @tparam TYPE
	 * @param os an output stream followed
	 * @param _obj the List to output
	 *
	 * @return the stream to output
	 */
	template <typename TYPE> std::ostream& operator<<(std::ostream &os, 
							const ArrayList<TYPE> &_obj); 

	/**
	 * @brief Using standard array in C++ to implement List ADT,TYPE can 
	 * be char, int, long, double or long double
	 *
	 * @tparam TYPE
	 */
	template <typename TYPE>
	class ArrayList {
	private:
	TYPE *__data;     /**< the data stored. */
	int __length;      /**< teh length of the list. */

	/**
	 * @brief Merge two  parts of the list, which are [_p, _q] and 
	 * [_q + 1, _r] ,the two parts should have alread sorted, then the 
	 * result oif merging [_p, _r] will be also sorted. This function is
	 * for the implementation of function __merge_sort() only.
	 *
	 * @param _p start index of part one
	 * @param _q The index before teh start of part two, and _q + 1 
	 * `			is the start of the part two.
	 * @param _r The end of the part two. _r - 1 is the index of the last 
	 *				element.
	 *
	 * @return If the List with its part [_p, _r] has already sorted, 
	 *				then return 0, otherwise return -1.
	 */
	int __merge(int _p,int _q,int _r);

	/**
	 * @brief Merge sort the part [_p, _r] of the List.
	 *
	 * @param _p The start index.
	 * @param _r Caution: the end index of the List is actually _r - 1.
	 *
	 * @return If everything is fine, return 0, otherwise -1
	 */
	int __merge_sort(int _p, int _r);

	public:
	/**
	 * @brief Default constructor. Build an empty list.
	 */
	ArrayList() {
		__data = NULL;
		__length = 0;
	};

	/**
	 * @brief Constructor, build a List with _s elements.
	 *
	 * @param _s The length of the List.
	 */
	ArrayList(int _s);

	/**
	 * @brief Constructor, build a List with _s elements, and all fill in
	 *			with value _d
	 *
	 * @param _s The length of the List
	 * @param _d The initial value for all elements
	 */
	ArrayList(int _s, TYPE _d);

	/**
	 * @brief Default destructor
	 */
	~ArrayList();

	/**
	 * @brief Print out all elemetns of the List.For debug using 
	 *
	 * @return If everything is fine, return 0, otherwise -1
	 */
	int printArrayList();

	/**
	 * @brief Find if the List contains value _d
	 *
	 * @param _d The value to find 
	 *
	 * @return The index of the first elewmetn with the value _d
	 *				if it was found, otherwise -1.
	 */
	int find(TYPE _d);

	/**
	 * @brief Find if the List contains value _d, using bisection
	 *			searching algorithm.
	 *
	 * @param _d The value to find
	 *
	 * @return The index of the first element with value _d if it was found
	 *			otherwise -1.
	 s*/
	int fast_find(TYPE _d);

	/**
	 * @brief Sort the List by merge-sort algorithm
	 *
	 * @return If everything is fine, return 0, otherwise -1.
	 */
	int merge_sort();

	/**
	 * @brief Reload operator [] for read/write the value of elements.
	 *
	 * @param _i The index of the element.
	 *
	 * @return If everything is fine, return 0, otherwise -1.
	 */
	TYPE &operator[](int _i);

	/**
	 * @brief Reload operator [] only for read the value of elements.
	 *
	 * @param _i The index of the element.
	 *
	 * @return If everything is fine, return 0, otherwise -1.
	 */
	const TYPE&operator[](int _i) const;

	friend std::ostream& operator<< <> (std::ostream&,  
						const ArrayList<TYPE>&);
	};
}
#else
//Do nothing.

#endif
