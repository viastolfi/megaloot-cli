#include "Player.hpp"

Player::Player()
  :stats{}, inventory{}, equipedWeapon{}
{}

Player::Player(std::list<Stat*> stats)
  :stats{stats}, inventory{}, equipedWeapon{}
{}

Player::Player(std::vector<Equipment*> inventory, std::list<Stat*> stats)
				:stats{stats}, inventory{inventory}
{}

void Player::addStat(Stat* stat) {
	stats.push_back(stat);
}

void Player::addEquipment(Equipment* e) {
	inventory.push_back(e);
} 

std::list<Stat*> Player::getStats() {
	return stats;
}

std::vector<Equipment*> Player::getEquipment() {
	return inventory;
}

void Player::equipWeapon(int index) {
  // NOTE : Possible futur error. Use dynamic_cast for better safety
  equipedWeapon = static_cast<Weapon*>(inventory[index]);
  inventory.erase(inventory.begin() + index);

  updateStat();
}

void Player::updateStat() {
  for (auto s : stats) {
    if (s->getStatName() == StatName::power) {
      s->setStatValue(equipedWeapon->getPower()); 
    }
  }
}

int Player::attack() {
  for (auto& s : getStats()) {
    if (s->getStatName() == StatName::power) {
      return s->getStatValue();
    }
  }

  return 0;
}

std::ostream& operator<<(std::ostream& os, Player& p) {
 	for (auto s : p.getStats()) {
		os << *s << "\n";
	}	

	return os;
}
