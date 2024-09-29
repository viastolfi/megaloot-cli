#include "Bow.hpp"

Bow::Bow(std::string name, std::string description)
				:Weapon(name, description)
{}

int Bow::attack() {
	return 24;
}

void Bow::print(std::ostream& os) {
	os << getRarity().getColorStringStart() << "Type : 🏹	 BOW" << ", Name : " << getName() << ", Rarity :" << getRarity()  << getRarity().getColorStringEnd();
}
