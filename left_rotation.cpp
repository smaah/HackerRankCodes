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



int main() {

	int n; // number of integers
	int d; // number of left rotations
    int duumm = 0;
	std::string Input_strng; // input stream
	std::string dummy;

	std::vector<int> aarra_y; // the original array
	std::vector<int> rot_aarra_y; // the roatetd array

	// get the first line
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream NUmB(Input_strng);
	NUmB >> dummy;
	n = atoi(dummy.c_str());
	dummy.clear();
	NUmB >> dummy;
	d = atoi(dummy.c_str());
	Input_strng.clear();
	dummy.clear();

	// get the array
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream ARR(Input_strng);
	for (unsigned int i = 0; i < n; i++) {
		ARR >> dummy;
		aarra_y.push_back(atoi(dummy.c_str()));
		dummy.clear();
	}

	//left rotation
	for (unsigned int j = 0; j < d; j++) {
		  aarra_y.push_back(*(aarra_y.begin()));
		aarra_y.erase(aarra_y.begin());
    }

	for (std::vector<int>::iterator it = aarra_y.begin(); it != aarra_y.end(); ++it)
		std::cout << *it << " ";
	std::cout << '\n';

    return 0;
}
