#include "Equipment.hpp"

Equipment::Equipment(std::string name, std::string description)
				:name{name}, description{description}
{
	rarity = new Rarity(RarityName::legendary);
}


std::string Equipment::getName() const {
	return name;
}

Rarity Equipment::getRarity() const{
	return *rarity;
}

std::ostream& operator<<(std::ostream& s, const Equipment& e) {
	s << e.getRarity().getColorStringStart() << "Object name : " << e.getName() << e.getRarity().getColorStringEnd();
	return s;
}
