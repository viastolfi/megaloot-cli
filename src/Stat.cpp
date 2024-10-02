#include "Stat.hpp"

Stat::Stat(StatName name, int value) 
	:stat{name, value}
{}

StatName Stat::getStatName() {
	return stat.first;
}

int Stat::getStatValue() {
	return stat.second;
}

void Stat::setStatValue(int value) {
  stat.second = value;
}

std::ostream& operator<<(std::ostream& os, Stat s) {
	os << "Stat name : " << s.getStatName() << ", Value : " << s.getStatValue(); 
	return os;
}
