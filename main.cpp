#include <iostream>
#include <cmath>
#include "System.h"
#include "Signal.h"
#include "IO.h"
#include <cmath>
#include <algorithm>

// noexcept kulcsszavakat kitenni

int main(int argc, char* argv[])
{

//	Signal input;
//	IO io;
//	io.read("test.wav", input);


	System sys{{100},{0.4,0.3,0.2}};

	Signal v = {0,0,1,0,0,0,0,0,0,0,0};

	sys.reset();
	Signal ans = sys.eval(v);

	for(auto i : ans){
		std::cout << i << std::endl;
	}

//
//	if(argv[0] == "start"){
//		std::cout << "start" << std::endl;
//	}else if(argv[0] == "valami"){
//		std::cout << "valami" << std::endl;
//	}else {
//		std::cout << "unknown command" << std::endl;
//	}


//	std::cout << "You have entered " << argc
//		 << " arguments:" << "\n";
//
//	for (int i = 0; i < argc; ++i)
//		std::cout << argv[i] << "\n";
//
//	return 0;


	return 0;
}
