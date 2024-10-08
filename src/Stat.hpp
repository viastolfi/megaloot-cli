#ifndef STAT_HPP
#define STAT_HPP

#include <iostream>
#include <tuple>

#include "enums/StatName.hpp"

class Stat {
private:
	std::pair<StatName, int> stat;
public:
	Stat(StatName name, int value);
	StatName getStatName();
	int getStatValue();
  void setStatValue(int value);
};

bool operator<(Stat s1, Stat s2);
std::ostream& operator<<(std::ostream& os, Stat s);

#endif //STAT-HPP
