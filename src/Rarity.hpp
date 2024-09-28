#ifndef RARITY_HPP
#define RARITY_HPP

#include <iostream>
#include <string>

#include "colorDefinition.hpp"
#include "RarityName.hpp"

class Rarity {
private: 
	RarityName name;
public:
	Rarity(RarityName name);
	RarityName getName();
	std::string getColorStringStart() const;
	std::string getColorStringEnd() const;
};

std::ostream& operator<<(std::ostream& s, Rarity r);

#endif //RARITY_HPP
