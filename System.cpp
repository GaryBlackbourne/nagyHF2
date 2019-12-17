#include "System.h"
#include <cmath>
#include <algorithm>


Signal System::eval(const Signal &input) {

	Signal Ans; 	// válasz jel létrehozása

	buffer.clear();	// buffer ürítése
	size_t buff_size = std::max(num.size(), den.size());
	buffer.resize(buff_size);

	for(auto i : buffer){
		i = 0;
	}

	int tmp = 0; // aktuális érték
	int k = 0;	//ciklusváltozó

	for(int l = 0; l < input.getSize()+buffer.size(); l++){ // összes tmp kiszámítása // todo: nem jó a lépésszám, de még lehet jó
		//----------------------------------------------------------------------------------
		k = 0;// todo : ronda

		for(auto i : num) {
			if(l-k >= 0 && l-k < input.getSize()){				// l-k >= 0 -- régebbi a gerjesztés mint T0 kiszűrése,
				tmp = tmp + (int)round(i*input[l-k]);
			}
			k++;
		}

		k = 0;

		for(auto j : den) {
			if(l-k >= 0 && k < buffer.size()){				// l-k >= 0 --
				tmp = tmp + (int)round(j*buffer[k]);
			}
			k++;
		}
		//----------------------------------------------------------------------------------

		std::rotate(buffer.begin(),buffer.end()-1,buffer.end());
		buffer[0] = tmp;

		//itt már tmp az aktuális válasz
		Ans.add(tmp);
		tmp = 0;
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