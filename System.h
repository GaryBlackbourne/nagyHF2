//
// Created by geri on 2019.11.27..
//

#ifndef NAGYHF2_SYSTEM_H
#define NAGYHF2_SYSTEM_H

#include <vector>

class System
{
private:
	std::vector<double> num;
	std::vector<double> den;
	std::vector<int> buffer;
//	buffer;
// 	buffer size = max(size(num), size(den))
public:
//	System();
//	System(std::vector<double>, std::vector<double>);
	~System() = default;



};

#endif