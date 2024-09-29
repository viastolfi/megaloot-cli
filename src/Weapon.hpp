#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

#include "Equipment.hpp"

class Weapon : public Equipment {
public:
	Weapon(std::string name, std::string description)
					: Equipment(name, description) {}
	virtual int attack() = 0;
	virtual void print(std::ostream& os) = 0;
	virtual ~Weapon() {}
};

#endif //WEAPON_HPP
