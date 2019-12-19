#include "System.h"
#include <cmath>
#include <algorithm>


Signal System::eval(const Signal &input) {

	if(buffer.empty()){
		throw std::runtime_error("empty buffer"); 	// todo: ennek 1/1-0 átvitelen nem kéne szerepet játszania
	}

	Signal Ans; 	// válasz jel létrehozása

	for(auto i : buffer){
		i = 0;
	}

	int tmp; // aktuális érték

	for(int l = 0; l < input.getSize()+buffer.size(); l++){ // összes tmp kiszámítása // todo: lépésszám becslése szükséges. lecsengésoi idő megadása pl....
		tmp = 0;

		//----------------------------------------------------------------------------------

		for(int k = 0; k < num.size(); k++) {
			if(l-k >= 0 && l-k < input.getSize()){
				tmp = tmp + (int)round(num[k]*input[l-k]);
			}
		}

		for(int k = 0; k < den.size(); k++) {			// todo: tippre itt kell valami
			if(l-k >= 0 && k < buffer.size()){
				tmp = tmp + (int)round(den[k]*buffer[k]);
			}
		}
		//----------------------------------------------------------------------------------

		std::rotate(buffer.begin(),buffer.end()-1,buffer.end());
		buffer[0] = tmp;

		//itt már tmp az aktuális válasz
		Ans.add(tmp);
	}

	return Ans;
}

System::System(std::initializer_list<double> nump, std::initializer_list<double> denp) {
	for(auto i : nump) {
		num.push_back(i);
	}
	for(auto j : denp){
		den.push_back(j);
	}
}

void System::reset() {
	buffer.clear();	// buffer ürítése
	size_t buff_size = den.size();
	buffer.resize(buff_size);
}

void System::setDen(std::vector<double>& denParam) {
	den = denParam;
}

void System::setNum(std::vector<double>& numParam) {
	num = numParam;
}

void System::setDen(std::vector<double>&& denParam) {
	den = denParam; // std::vector operator = --> move
}

void System::setNum(std::vector<double>&& numParam) {
	num = numParam;
}