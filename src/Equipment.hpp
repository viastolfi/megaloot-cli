#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <iostream>
#include <string>
#include <list>

#include "Rarity.hpp"
#include "Stat.hpp"

class Equipment {
private:
	std::string name;
	std::string description;	
	Rarity rarity = RarityName::common;
	std::list<Stat> stats = {};
public:
	Equipment(std::string name, std::string description, std::list<Stat> stats)
					:name{name}, description{description}, stats{stats}
		{
			setRarity();
		}
	Equipment(std::string name, std::string description)
					:name{name}, description{description}
		{
			setRarity();
		}

	inline void setRarity() {
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

	inline void addStat(Stat stat) { stats.push_back(stat); } 
	inline std::list<Stat> getStats() { return stats; }
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
