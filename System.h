//
// Created by geri on 2019.11.27..
//

#ifndef NAGYHF2_SYSTEM_H
#define NAGYHF2_SYSTEM_H

#include <vector>
#include <initializer_list>
#include "Signal.h"

class System
{
private:
	std::vector<double> num;
	std::vector<double> den;
	std::vector<int> buffer; //

public:
	System() = default;
	System(std::initializer_list<double>, std::initializer_list<double>);
	~System() = default;


	Signal eval(const Signal&); // adott bemeneti jelből adott kimeneti jelben

};

#endif