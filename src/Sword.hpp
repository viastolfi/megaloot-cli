#ifndef SWORD_HPP
#define SWORD_HPP

#include <string>
#include <iostream>

#include "Weapon.hpp"

class Sword : public Weapon {
public:
	Sword(std::string name, std::string description);
	int attack() override;	
	void print(std::ostream& os) override;
	~Sword() override {}
};

#endif //SWORD_HPP
