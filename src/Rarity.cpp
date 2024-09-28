#include "Rarity.hpp"

Rarity::Rarity(RarityName name)
				:name{name}
{}

RarityName Rarity::getName() {
	return name;
}

std::string Rarity::getColorStringStart() const {
	switch(name) {
		case RarityName::legendary:
			return ORANGE_START;
		case RarityName::common:
			return GREEN_START;
		case RarityName::epic:
			return PURPLE_START;
		case RarityName::rare:
			return BLUE_START;
		default:
			return "not implemented";
	}
}

std::string Rarity::getColorStringEnd() const {
	return "\033[0m";
}


std::ostream& operator<<(std::ostream& s, Rarity r) {
	s << r.getName();
	return s;
}


