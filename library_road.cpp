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
#include <fstream>
#include <utility>

int main() {

	double N = 0; // number of trials
	double N_c = 0; // number of cities
	double N_r = 0; // number of roads
	double C_lib = 0; // cost of library
	double C_road = 0; // cost of road
	double t_circuit = 0;
	double t_path = 0;
	double cost = 0;
	std::ifstream f;
	std::string Input_strng; // input stream
	std::string dummy;

	f.open("input08.txt");
	// get the first line
	std::getline(f, Input_strng, '\n');
	std::istringstream NUmB(Input_strng);
	NUmB >> dummy;
	N = atoi(dummy.c_str());
	Input_strng.clear();
	dummy.clear();

	for (int n = 0; n < N; ++n) {
		// get the second line
		std::getline(f, Input_strng, '\n');
		std::istringstream NARR(Input_strng);

		NARR >> dummy;
		N_c = atof(dummy.c_str());
		Input_strng.clear();
		dummy.clear();

		NARR >> dummy;
		N_r = atof(dummy.c_str());
		Input_strng.clear();
		dummy.clear();

		NARR >> dummy;
		C_lib = atof(dummy.c_str());
		Input_strng.clear();
		dummy.clear();

		NARR >> dummy;
		C_road = atof(dummy.c_str());
		Input_strng.clear();
		dummy.clear();

		//std::cout<< N_c <<" " << N_r << " " <<C_lib << " " <<C_road <<std::endl;

		std::vector < std::vector<double> > roads_c(N_c, std::vector<double>());

		std::vector<double> r_org(N_r, 0); //origin
		std::vector<double> r_dest(N_r, 0); // destination

		// get the array
       // if(n == 0){
		for (int i = 0; i < N_r; i++) {
			std::getline(f, Input_strng, '\n');
			std::istringstream ARR(Input_strng);
			ARR >> dummy;
			r_org[i] = atoi(dummy.c_str());
			ARR >> dummy;
			r_dest[i] = atoi(dummy.c_str());
			dummy.clear();
			roads_c[int(r_org[i] - 1)].push_back(r_dest[i]);
			roads_c[int(r_dest[i] - 1)].push_back(r_org[i]);
		}

		if (N_r < 1) {

			cost = N_c * C_lib;

		} else {

			for (int m = 0; m < N_c; m++) {

				//lim_t = roads_c[m].size();

				//if (lim_t > 0 && m < N_c) {

				for (int i = 0; i < roads_c[m].size(); ++i) {

					int ind = int(roads_c[m][i] - 1);

					if (ind != m && !roads_c[ind].empty()) {

						roads_c[m].insert(roads_c[m].begin() + i + 1,
								roads_c[ind].begin(), roads_c[ind].end());

						roads_c[ind].clear();

					}
				}

				roads_c[m].push_back(m + 1);
				std::sort(roads_c[m].begin(), roads_c[m].end());
				std::vector<double>::iterator it = std::unique(roads_c[m].begin(),
						roads_c[m].end());
				roads_c[m].resize(std::distance(roads_c[m].begin(), it));

				//}

				if (roads_c[m].size() > 1) {
					t_path += (roads_c[m].size() - 1);
					++t_circuit;
				}

				if (!roads_c[m].empty())
					roads_c[m].clear();

			}

			// minimum cost
			if ((2 * C_lib) < C_road) {
				cost = C_lib * N_c;
				//	std::cout << 1 <<" " <<t_circuit<< " "<<t_path<<std::endl;
			} else {
				if (N_c > (t_circuit + t_path)) {
					cost = C_lib * t_circuit + t_path * C_road
							+ (N_c - t_circuit - t_path) * C_lib;
					//	std::cout << 2<<" " <<t_circuit<< " "<<t_path<<std::endl;
				} else {
					cost = C_lib * t_circuit + t_path * C_road;
					//	std::cout << 3 <<" " <<t_circuit<< " "<<t_path<<std::endl;
				}
			}

		}

		if (N_c * C_lib > cost){
			std::cout.precision(12);
			//std::cout.width(10);
			std::cout << (cost) << std::endl;}
		else{
			std::cout.precision(12);
			//std::cout.width(10);
			std::cout<< (N_c * C_lib) << std::endl;
		}
	//}

		t_path = 0;
		t_circuit = 0;
		r_org.clear();
		r_dest.clear();


	}

	return 0;
}
