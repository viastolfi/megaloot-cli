#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <iostream>
#include <string>

#include "EquipmentType.hpp"
#include "Rarity.hpp"

class Equipment {
private:
	std::string name;
	std::string description;	
	EquipmentType type = EquipmentType::sword;
	Rarity* rarity;
public:
	Equipment(std::string name, std::string description, EquipmentType type);
 	std::string getName() const;
	Rarity getRarity() const;
	EquipmentType getType() const;
};

std::ostream& operator<<(std::ostream& s, const Equipment& e);

#endif //EQUIPMENT_HPP
