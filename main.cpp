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
	std::string inputFile = "defaultIn.wav";
	std::string outputFile = "defaultOut.wav";
	std::vector<double> numParam;
	std::vector<double> denParam;
	//System sys;

	for (int i = 1; i < argc; i ++){
		if(std::string{argv[i]} == "--input") {
			if(argc > i + 1){
				i++;
				inputFile = argv[i];
			}
		}else if(std::string{argv[i]} == "--output"){
			if(argc > i + 1){
				i++;
				outputFile = argv[i];
			}
		}else if(std::string{argv[i]} == "--num"){
			bool run = true;
			i++;
			while(run && argc > i){
				try
				{
					numParam.push_back(std::stod(argv[i]));
					i++;
				}catch (std::invalid_argument&){
					run = false;
					i--;
				}
			}
		}else if(std::string{argv[i]} == "--den"){
			bool run = true;
			i++;
			while(run && argc > i){
				try
				{
					denParam.push_back(std::stod(argv[i]));
					i++;
				}catch (std::invalid_argument&){
					run = false;
					i--;
				}
			}
		}else{
			std::cout << "Invalid argument: " << argv[i] << std::endl;
		}
	}






//	Signal input;
//	IO io;
//	io.read("test.wav", input);


//	System sys{{100},{0.4,0.3,0.2}};
//
//	Signal v = {0,0,1,0,0,0,0,0,0,0,0};
//
//	sys.reset();
//	Signal ans = sys.eval(v);
//
//	for(auto i : ans){
//	s	std::cout << i << std::endl;
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
