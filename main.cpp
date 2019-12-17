#include <iostream>
#include <cmath>
#include "System.h"
#include "Signal.h"
#include "IO.h"
#include <cmath>
#include <algorithm>

// noexcept kulcsszavakat kitenni

int main(int agrc, char* argv[])
{

	Signal input;
	IO io;
	io.read("test.wav", input);


	System sys{{1},{0.5}};

	Signal v = {0,0,100,50,0,0,0,0};

	Signal ans = sys.eval(v);

	for(auto i : ans){
		std::cout << i << std::endl;
	}

//
//	std::vector<int> test = {0,0,0,1,0,0,0,};
//	std::rotate(test.begin(), test.end()-1, test.end());
//	for(auto j : test){
//		std::cout << j;
//	}


	return 0;
}
