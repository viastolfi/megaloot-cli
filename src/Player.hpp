#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <list>

#include "Stat.hpp"
#include "Equipment.hpp"
#include "Weapon.hpp"

class Player {
private:
	std::list<Stat*> stats;
	std::vector<Equipment*> inventory;
  Weapon* equipedWeapon;
public:
  Player();
  Player(std::list<Stat*> stats);
	Player(std::vector<Equipment*> inventory, std::list<Stat*> stats);
	void addStat(Stat* stat);
	void addEquipment(Equipment* e);
  int attack();
  void getDamaged(int damage);
  void equipWeapon(int index);
  void equipItem(int index);
  void updateStat();
  int getHp();
  void showInventory();
	std::list<Stat*> getStats();
	std::vector<Equipment*> getEquipment();
  ~Player();
};

std::ostream& operator<<(std::ostream& os, Player& p);

#endif //PLAYER_HPP
