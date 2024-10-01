#ifndef STATNAME_HPP
#define STATNAME_HPP

#include <iostream>

enum StatName {
	hp,
	power,
};

inline std::ostream& operator<<(std::ostream& os, StatName sn) {
	switch(sn) {
	case power: 
		os << "power";
		break;
  case hp:
    os << "hp";
    break;
	default:
		os << "Not Implemented";
		break;
	}

	return os;
}

#endif //STATNAME_HPP
