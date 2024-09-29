#ifndef BOW_HPP
#define BOW_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class Bow : public Weapon {
public:
	Bow(std::string name, std::string description);
	int attack() override;	
	void print(std::ostream& os) override;
	~Bow() override {}
};

#endif // BOW_HPP
