#include "Rarity.hpp"
#include "colorDefinition.hpp"

Rarity::Rarity(RarityName name)
				:name{name}
{}

std::string Rarity::getColorStringStart() const {
	switch(name) {
		case RarityName::legendary:
			return ORANGE_START;
		default:
			return "not implemented";
	}
}

std::string Rarity::getColorStringEnd() const {
	switch(name) {
		case RarityName::legendary:
			return ORANGE_END;
		default:
			return "not implemented";
	}	
}
