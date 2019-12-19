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
	std::vector<int> buffer;

public:
	System(std::initializer_list<double> = {1}, std::initializer_list<double> = {0});

	~System() = default;

	void setNum(std::vector<double> &);

	void setDen(std::vector<double> &);

	void setNum(std::vector<double> &&);

	void setDen(std::vector<double> &&);

	Signal eval(const Signal &); // adott bemeneti jelből adott kimeneti jelben
	void reset();

//	bool stable() const;

};

#endif