#ifndef BOW_HPP
#define BOW_HPP

#include <iostream>
#include <string>
#include <list>

#include "Stat.hpp"
#include "Weapon.hpp"

class Bow : public Weapon {
public:
  Bow(std::string name, std::string description, Rarity r);
  Bow(std::string name, std::string description, Rarity r, std::list<Stat> stats);
	Bow(std::string name, std::string description, std::list<Stat> stats);
	Bow(std::string name, std::string description);
	int attack() override;	
	void print(std::ostream& os) override;
	~Bow() override {}
};

#endif // BOW_HPP
