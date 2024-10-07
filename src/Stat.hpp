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

std::ostream& operator<<(std::ostream& os, Stat s);

#endif //STAT-HPP
