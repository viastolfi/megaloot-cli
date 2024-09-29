#include "Sword.hpp"

Sword::Sword(std::string name, std::string description) 
	: Weapon(name, description)
{}

int Sword::attack() {
	return 12;
}

void Sword::print(std::ostream& os) {
	os << getRarity().getColorStringStart() << "Type : 🗡️  SWORD" << ", Name : " << getName() << ", Rarity :" << getRarity()  << getRarity().getColorStringEnd();
}
