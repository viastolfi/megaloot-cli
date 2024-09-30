#ifndef STAT_HPP
#define STAT_HPP

#include <iostream>
#include <tuple>

#include "StatName.hpp"

class Stat {
private:
	std::pair<StatName, int> stat;
public:
	Stat(StatName name, int value);
	StatName getStatName();
	int getStatValue();
};

std::ostream& operator<<(std::ostream& os, Stat s);

#endif //STAT-HPP
