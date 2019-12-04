#include <iostream>
#include <cmath>
#include "Signal.h"
#include "IO.h"
#include <cmath>

// noexcept kulcsszavakat kitenni

int main()
{

	Signal input;
	IO io;
	io.read("test.wav", input);
//
//	std::cout << "KosziKoza" << std::endl;
//
////
////	// do something
////
////	Signal out;
	io.write("testOut.wav", input);

	std::cout << std::hex << *(input.end()-1) << std::endl;
	std::cout << std::hex << *(input.end()-2) << std::endl;
	std::cout << std::hex << *(input.end()-3) << std::endl;
//	Signal s1 = {0,1,3,5,9,5,2,6,8,4,9};
//
//	for(int i = 0; i < 7; i++){
//		std::cout << s1 [i] << std::endl;
//	}


//	 int a = 5;
//	 double b = 3.255;
//
//	 double z = a*b;
//
//	 int s = (int)round(z);
//
//	std::cout << round(a*b) << std::endl;
//

	return 0;
}
