#include "Sword.hpp"

Sword::Sword(std::string name, std::string description, Rarity r)
  : Weapon(name, description, r)
{}

Sword::Sword(std::string name, std::string description, std::list<Stat> stats) 
	: Weapon(name, description, stats)
{}


Sword::Sword(std::string name, std::string description) 
	: Weapon(name, description)
{}

int Sword::attack() {
	return 12;
}

void Sword::print(std::ostream& os) {
	os << getRarity().getColorStringStart() << "Type : 🗡️  SWORD" << ", Name : " << getName() << getRarity().getColorStringEnd();
}
