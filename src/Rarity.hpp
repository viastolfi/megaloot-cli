#ifndef RARITY_HPP
#define RARITY_HPP

#include <string>

#include "RarityName.hpp"

class Rarity {
private: 
	RarityName name;
public:
	Rarity(RarityName name);
	std::string getColorStringStart() const;
	std::string getColorStringEnd() const;
};


#endif //RARITY_HPP
