#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <list>

#include "Stat.hpp"
#include "Equipment.hpp"

class Player {
private:
	std::list<Stat> stats;
	std::vector<Equipment*> inventory;
public:
	Player(std::vector<Equipment*> inventory, std::list<Stat> stats);
	void addStat(Stat stat);
	void addEquipment(Equipment* e);
	std::list<Stat> getStats();
	std::vector<Equipment*> getEquipment();
};

std::ostream& operator<<(std::ostream& os, Player& p);

#endif //PLAYER_HPP
