#include "Signal.h"

Signal::Signal(std::initializer_list<int> list){
	for(auto i : list){
		data.push_back(i);
	}
};

const int& Signal::operator[](size_t i) const{
	return data[i];
}

size_t Signal::getSize() const {
	return data.size();
}

void Signal::add(int a) {
	data.push_back(a);
}

std::vector<int>::const_iterator Signal::begin() const {
	return data.begin();
}

std::vector<int>::const_iterator Signal::end() const {
	return data.end();
}

std::vector<int>::iterator Signal::begin() {
	return data.begin();
}

std::vector<int>::iterator Signal::end() {
	return data.end();
}