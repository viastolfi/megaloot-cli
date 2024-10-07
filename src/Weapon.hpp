#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <list>

#include "Equipment.hpp"
#include "Stat.hpp"

class Weapon : public Equipment {
public:
  Weapon(std::string name, std::string description, Rarity r)
    : Equipment(name, description, r) {}
	Weapon(std::string name, std::string description)
					: Equipment(name, description) {}
	Weapon(std::string name, std::string description, Rarity r, std::list<Stat> stats)
    : Equipment(name, description, r, stats) {}
	Weapon(std::string name, std::string description, std::list<Stat> stats)
					: Equipment(name, description, stats) {}
  inline int getPower() {
    for (auto s : getStats()) {
      if (s.getStatName() == StatName::power) {
        return s.getStatValue();
      }
    }

    return 0;
  }
	virtual int attack() = 0;
	virtual void print(std::ostream& os) = 0;
	virtual ~Weapon() {}
};

#endif //WEAPON_HPP
