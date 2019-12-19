#include <iostream>
#include <cmath>
#include "System.h"
#include "Signal.h"
#include "IO.h"
#include <cmath>
#include <algorithm>


int main(int argc, char *argv[]) {

	std::string inputFile = "defaultIn.wav";
	std::string outputFile = "defaultOut.wav";

	std::vector<double> numParam = {1};
	std::vector<double> denParam = {0};

	System sys;

	Signal input;
	IO io;


	for (int i = 1; i < argc; i++) {
		if (std::string{argv[i]} == "--input") {
			if (argc > i + 1) {
				i++;
				inputFile = argv[i];
			}
		} else if (std::string{argv[i]} == "--output") {
			if (argc > i + 1) {
				i++;
				outputFile = argv[i];
			}
		} else if (std::string{argv[i]} == "--num") {
			bool run = true;
			i++;
			while (run && argc > i) {
				try {
					numParam.push_back(std::stod(argv[i]));
					i++;
				} catch (std::invalid_argument &) {
					run = false;
					i--;
				}
			}
		} else if (std::string{argv[i]} == "--den") {
			bool run = true;
			i++;
			while (run && argc > i) {
				try {
					denParam.push_back(std::stod(argv[i]));
					i++;
				} catch (std::invalid_argument &) {
					run = false;
					i--;
				}
			}
		} else {
			std::cout << "Invalid argument: " << argv[i] << std::endl;
		}
	}

	sys.setNum(numParam);
	sys.setDen(denParam);

	try {
		io.read(inputFile, input);
	} catch (std::ios_base::failure &error) {
		std::cerr << error.what() << std::endl;
		return 1;
	}

	sys.reset();    // set/reset buffer
	Signal output = sys.eval(input);

	try {
		io.write(outputFile, output);
	} catch (std::ios_base::failure &error) {
		std::cerr << error.what() << std::endl;
	}

	return 0;
}
