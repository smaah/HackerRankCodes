/*
 * main.cpp
 *
 *  Created on: Apr 20, 2017
 *      Author: sayed
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>

int main() {

	int n; // number of candles
	std::string Input_strng; // input stream
	std::string dummy;
	int number;

	std::vector<int> cndl_hgt(n); // the original array

	// get the first line
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream NUmB(Input_strng);
	NUmB >> dummy;
	n = atoi(dummy.c_str());
	dummy.clear();

	// get the candle height
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream ARR(Input_strng);
	for (unsigned int i = 0; i < n; i++) {
		ARR >> dummy;
		cndl_hgt.push_back(atoi(dummy.c_str()));
		dummy.clear();
	}

	//left rotation
	std::sort(cndl_hgt.begin(), cndl_hgt.end());
	for (std::vector<int>::iterator it = cndl_hgt.begin(); it < cndl_hgt.end(); ++it)
			std::cout << *it << " ";

	number = std::count(cndl_hgt.begin(), cndl_hgt.end(), *(cndl_hgt.end()-1));
	std::cout << number << std::endl;

	return 0;

}
