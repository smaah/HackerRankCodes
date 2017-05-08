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


int main() {

	int M; // number of rows
	int N; // number of columns
	int R; // number of left rotations
	std::string Input_strng; // input stream
	std::string dummy;

	// get the first line
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream NUmB(Input_strng);
	NUmB >> dummy;
	M = atoi(dummy.c_str());
	dummy.clear();
	NUmB >> dummy;
	N = atoi(dummy.c_str());
	Input_strng.clear();
	dummy.clear();
	NUmB >> dummy;
	R = atoi(dummy.c_str());
	dummy.clear();

	int num_level = std::min(M, N) / 2;
	std::vector < std::vector<int> > aarra_y(M, std::vector<int>(N)); // the original array
	std::vector <int > rot_aarra_y; // the rotated array

	// get the array
	for (unsigned int i = 0; i < M; i++) {
		std::getline(std::cin, Input_strng, '\n');
		std::istringstream ARR(Input_strng);
		for (unsigned int j = 0; j < N; j++) {
			ARR >> dummy;
			aarra_y[i][j] = atoi(dummy.c_str());
			dummy.clear();
		}
	}

	for (int i = 0; i < num_level; ++i) {

		for (int j = i; j < N - i; ++j) {
			rot_aarra_y.push_back(aarra_y[i][j]);
		}

		for (int j = i + 1; j < M - i; ++j) {
			rot_aarra_y.push_back(aarra_y[j][N - 1 - i]);
		}

		for (int j = N - 2 - i; j >= i; --j) {
			rot_aarra_y.push_back(aarra_y[M - 1 - i][j]);
		}

		for (int j = M - 2 - i; j >= i + 1; --j) {
			rot_aarra_y.push_back(aarra_y[j][i]);
		}

        int siz_e = rot_aarra_y.size();
        int rot = (R%siz_e);
        for (int j = 0; j < rot; j++) {
			rot_aarra_y.push_back(*(rot_aarra_y.begin()));
        	rot_aarra_y.erase(rot_aarra_y.begin());
		}

        std::vector<int>::iterator it = rot_aarra_y.begin();

		for (int j = i; j < N - i; ++j) {
			aarra_y[i][j] = *it++;
		}

		for (int j = i + 1; j < M - i; ++j) {
			aarra_y[j][N - 1 - i] = *it++;
		}

		for (int j = N - 2 - i; j >= i; --j) {
			aarra_y[M - 1 - i][j] = *it++;
		}

		for (int j = M - 2 - i; j >= i + 1; --j) {
			aarra_y[j][i] = *it++;
		}
        rot_aarra_y.clear();
	}


	for (unsigned int i = 0; i < M; i++) {
		for (unsigned int j = 0; j < N; j++) {
			std::cout << aarra_y[i][j] << " ";
		}
		std::cout << '\n';
	}

	return 0;
}
