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

bool operator<(Stat s1, Stat s2) {
  return static_cast<int>(s1.getStatName()) < static_cast<int>(s2.getStatName());
}

std::ostream& operator<<(std::ostream& os, Stat s) {
	os << "Stat name : " << s.getStatName() << ", Value : " << s.getStatValue(); 
	return os;
}
