#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <iostream>
#include <string>

#include "Rarity.hpp"

class Equipment {
private:
	std::string name;
	std::string description;	
	Rarity rarity = RarityName::common;
public:
	Equipment(std::string name, std::string description)
					:name{name}, description{description}
		{
			float randomValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			if (randomValue < 0.5) {
				rarity = Rarity(RarityName::common);
				return;
			} 
			else if (randomValue < 0.8) {
				rarity = Rarity(RarityName::rare);	
				return;
			}
			else if (randomValue < 0.9) {
				rarity = Rarity(RarityName::epic);
				return;
			}
			else {
				rarity = Rarity(RarityName::legendary);
				return;
			}	
		}
	inline std::string getName() { return name; }
	inline std::string getDescription() { return description; }
	inline Rarity getRarity() { return rarity; }
	virtual void print(std::ostream& os) = 0;
	virtual ~Equipment() {}
};

inline std::ostream& operator<<(std::ostream& os, Equipment& e) {
	e.print(os);
	return os;
};
#endif //EQUIPMENT_HPP
