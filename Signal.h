#ifndef NAGYHF2_SIGNAL_H
#define NAGYHF2_SIGNAL_H

#include <vector>
#include <iostream>
#include <initializer_list>

class Signal
{
private:
	std::vector<int> data;

public:
	Signal() = default;

	Signal(std::initializer_list<int>);
//	Signal(const Signal	&);
//	Signal(const Signal &&); // ide kell ez ??
//	Signal(int arg ...){
//		data{arg};
//	}

	~Signal() = default;

	size_t getSize() const noexcept;

	const int &operator[](size_t) const;

	std::vector<int>::const_iterator begin() const noexcept;

	std::vector<int>::iterator begin() noexcept;

	std::vector<int>::const_iterator end() const noexcept;

	std::vector<int>::iterator end() noexcept;

	void add(int); // push_back;
	// capacity() vel állíthatjuk a lefoglalt memória mennyiségét
	// shrink_to_fit() el visszaadhatjuk a felesleges memóriát
};


#endif //NAGYHF2_SIGNAL_H
