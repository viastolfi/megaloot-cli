#ifndef RARITYNAME_HPP
#define RARITYNAME_HPP

#include <iostream>

enum RarityName {
	common,
	rare,
	epic,
	legendary,
};

inline std::ostream& operator<<(std::ostream& s, RarityName rn) {
	switch(rn) {
		case common:
			s << "common";
			break;
		case rare:
			s << "rare";
			break;
		case epic:
			s << "epic";
			break;
		case legendary:
			s << "legendary";
			break;
		default:
			s << "Something went wrong";
			break;
	}
	return s;
}

#endif //RARITYNAME_HPP
