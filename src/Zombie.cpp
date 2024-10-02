#include "Zombie.hpp"

Zombie::Zombie(std::list<Stat*> stats) 
				:Ennemy(stats)
{}

int Zombie::attack() {
	for (auto s : getStats()) {
		if (s->getStatName() == StatName::power) {
			return s->getStatValue();
		}
	}

	return -1;
}

int Zombie::getDamaged(int damage) {
  for (auto s : getStats()) {
    if (s->getStatName() == StatName::hp) {
      s->setStatValue(s->getStatValue() - damage);
      return s->getStatValue();
    } 
  }

  return 0;
}

void Zombie::print(std::ostream& os) {
	os << "🧟  ZOMBIE :\n";
 	os << "STATS : \n";	
	for (auto s : getStats()) {
		os << *s << "\n";
	}
}
