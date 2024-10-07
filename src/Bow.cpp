#include "Bow.hpp"

Bow::Bow(std::string name, std::string description, Rarity r)
  :Weapon(name, description, r)
{}

Bow::Bow(std::string name, std::string description, Rarity r, std::list<Stat> stats)
  :Weapon(name, description, r, stats)
{}

Bow::Bow(std::string name, std::string description, std::list<Stat> stats)
				:Weapon(name, description, stats)
{}

Bow::Bow(std::string name, std::string description)
				:Weapon(name, description)
{}

int Bow::attack() {
	return 24;
}

void Bow::print(std::ostream& os) {
	os << getRarity().getColorStringStart() << "Type : 🏹  BOW" << ", Name : " << getName() << getRarity().getColorStringEnd();
}
