#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <list>
#include <iostream>

#include "Ennemy.hpp"

class Zombie : public Ennemy {
public:
	Zombie(std::list<Stat*> stats);
	int attack() override;
	void print(std::ostream& os) override;
  int getDamaged(int damage) override;
};

#endif //ZOMBIE_HPP
