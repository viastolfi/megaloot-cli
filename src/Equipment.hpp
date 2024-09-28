#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <iostream>
#include <string>

#include "Rarity.hpp"
#include "RarityName.hpp"

class Equipment {
private:
	std::string name;
	std::string description;	
	Rarity* rarity;
public:
	Equipment(std::string name, std::string description);
 	std::string getName() const;
	Rarity getRarity() const;
};

std::ostream& operator<<(std::ostream& s, const Equipment& e);

#endif //EQUIPMENT_HPP
