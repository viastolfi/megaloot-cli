#include "Equipment.hpp"

Equipment::Equipment(std::string name, std::string description, EquipmentType type)
				:name{name}, description{description}, type{type}
{
	float randomValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	if (randomValue < 0.5) {
		rarity = new Rarity(RarityName::common);
		return;
	} 
	else if (randomValue < 0.8) {
		rarity = new Rarity(RarityName::rare);	
		return;
	}
	else if (randomValue < 0.9) {
		rarity = new Rarity(RarityName::epic);
		return;
	}
	else {
		rarity = new Rarity(RarityName::legendary);
		return;
	}
}

EquipmentType Equipment::getType() const {
	return type;
}


std::string Equipment::getName() const {
	return name;
}

Rarity Equipment::getRarity() const{
	return *rarity;
}

std::ostream& operator<<(std::ostream& s, const Equipment& e) {
	s << e.getRarity().getColorStringStart() << "Type : " << e.getType() <<", Name : " << e.getName() << ", Rarity :" << e.getRarity()  << e.getRarity().getColorStringEnd();
	return s;
}
