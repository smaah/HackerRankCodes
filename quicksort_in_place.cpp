/*
 * main.cpp
 *
 *  Created on: Apr 20, 2017
 *      Author: sayed
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>


int partition(std::vector<int>&A, int lo, int hi);

void quick_sort(std::vector<int>&A, int lo, int hi);

void quick_sort(std::vector<int>& A, int lo, int hi){
    if (lo < hi){
        int p = partition(A, lo, hi);
        for(auto ii : A ) std::cout<< ii << " ";
        std::cout<<std::endl;
        quick_sort(A, lo, p- 1);
        quick_sort(A, p + 1, hi);
    }
}

int partition(std::vector<int>&A, int lo, int hi){
	int pivot = A[hi];
	int i = lo - 1;
	for (int j = lo;  j< hi; j++){
		if (A[j] <= pivot){
			i = i + 1;
			std::swap(A[i], A[j]);}
	}

	std::swap (A[i+1],A[hi]);

	return i + 1;
}

int main() {

	int N_Array = 0; // length of array
	int lo = 1;
	int hi = 0;
	std::string Input_strng; // input stream
	std::string dummy;

	// get the first line
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream NARR(Input_strng);
	NARR >> dummy;
	N_Array = atoi(dummy.c_str());
	Input_strng.clear();
	dummy.clear();
	//  std::cout<<N_Array<<std::endl;
	hi = N_Array-1;

	std::vector<int> aarra_y(N_Array,0);

	// get the array
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream ARR(Input_strng);
	for (int i = 0; i < N_Array; i++) {
		ARR >> dummy;
		aarra_y[i] = atoi(dummy.c_str());
		dummy.clear();
	}

   	quick_sort(aarra_y, lo-1, hi);

    aarra_y.clear();




	return 0;
}

