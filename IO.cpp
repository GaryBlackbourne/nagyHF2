#include "IO.h"
#include <iostream>
#include <fstream>

void IO::read(std::string filename, Signal& input) {
	std::ifstream is(filename, std::ifstream::binary);

	if(!is){
		throw std::ios_base::failure("input file not found");
	}



	//IO inicializálása // todo : figyelni a little big endianos sorrendre :)
	is.read(RIFF, 12);
	is.read(fmt, 24);
	is.read(dataSub, 8);

	// data olvasása Signal-ba.

	int tmpd;
	is.read(reinterpret_cast<char*>(&tmpd), 4);

	while (!is.eof()){

		input.add(tmpd);
		is.read(reinterpret_cast<char*>(&tmpd), 4);

	}


	is.close();

}

void IO::write(std::string filename, const Signal& output) {
	std::ofstream os(filename, std::ofstream::binary);

	if(!os){
		throw std::ios_base::failure("failed to write output file!");
	}

	// inicializált IO alapján riff fmt data chunk irások
	os.write(RIFF, sizeof(RIFF));
	os.write(fmt, sizeof(fmt));
	os.write(dataSub, sizeof(dataSub));


	for(auto i : output){
		os.write(reinterpret_cast<const char*>(&i), 4);
	}

	os.close();
}

void IO::clear() {
	for(auto i : RIFF){
		i = 0;
	}
	for(auto i : fmt){
		i = 0;
	}
	for(auto i : dataSub){
		i = 0;
	}
}
