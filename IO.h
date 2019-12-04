//
// Created by geri on 2019.11.27..
//

#ifndef NAGYHF2_IO_H
#define NAGYHF2_IO_H

#include <string>
#include "Signal.h"

class IO
{
private:
	// random WAV data tárolása
	char RIFF[3*4]; 	//int 4 byteos -> 3x4 byte a riffnek
	char fmt[6*4];		// 4*4 + 2*(2+2) 6*4 byte az fmt subchunk-nak
	char dataSub[2*4]; // 2x4 byte a data subchunknak
public:
	IO() = default;		// todo
	~IO() = default; 	// todo
	void read(std::string filename, Signal& input);
	void write(std::string filename, const Signal& output); // todo:: signal return valueval értelmesebb lenne
};


#endif //NAGYHF2_IO_H
