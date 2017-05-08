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

int main() {

	int N = 0; // number of trials
	int N_Array = 0; // length of array
    int su_m = 0;
    int su_m_r = 0;
    int count_o = 0 ;
    int count_1 = 0 ;
    int count_2 = 0 ;
	std::string Input_strng; // input stream
	std::string dummy;

	// get the first line
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream NUmB(Input_strng);
	NUmB >> dummy;
	N = atoi(dummy.c_str());
	Input_strng.clear();
	dummy.clear();
 //   std::cout<<N<<std::endl;

    for (int n = 0 ; n<N; ++n){
	// get the second line
	std::getline(std::cin, Input_strng, '\n');
	std::istringstream NARR(Input_strng);
	NARR >> dummy;
	N_Array = atoi(dummy.c_str());
	Input_strng.clear();
	dummy.clear();
  //  std::cout<<N_Array<<std::endl;

	std::vector<int> aarra_y(N_Array,0);
	std::vector<int> rem_(N_Array,3);


	// get the array
    std::getline(std::cin, Input_strng, '\n');
	std::istringstream ARR(Input_strng);
	for (int i = 0; i < N_Array; i++) {
		ARR >> dummy;
		aarra_y[i] = atoi(dummy.c_str());
		dummy.clear();
	}

	su_m = std::accumulate(aarra_y.begin(),aarra_y.end(),su_m);

	std::transform (aarra_y.begin(), aarra_y.end(), rem_.begin(), aarra_y.begin(),std::modulus<int>());

    su_m_r = std::accumulate(aarra_y.begin(),aarra_y.end(),su_m_r);

    count_o = std::count (aarra_y.begin(), aarra_y.end(), 0);
    count_1 = std::count (aarra_y.begin(), aarra_y.end(), 1);
    count_2 = std::count (aarra_y.begin(), aarra_y.end(), 2);

    count_o == N_Array ? std::cout<<"Koca" << std::endl  :
        (count_2%2 !=0 & su_m_r%2 == 0 ? std::cout<< "Balsa" << std::endl :
        (count_1 == N_Array & su_m_r%2 == 0 ? std::cout<< "Koca" << std::endl :
         ((count_1 != 0 & su_m_r%2 == 0 ? std::cout<< "Koca" << std::endl :
          std::cout<< "Balsa" << std::endl))));


    aarra_y.clear();


    su_m = 0;
    su_m_r = 0;

    }





	return 0;
}
