#include "Player.hpp"

Player::Player()
  :stats{}, inventory{}
{}

Player::Player(std::list<Stat> stats)
  :stats{stats}, inventory{}
{}

Player::Player(std::vector<Equipment*> inventory, std::list<Stat> stats)
				:stats{stats}, inventory{inventory}
{}

void Player::addStat(Stat stat) {
	stats.push_back(stat);
}

void Player::addEquipment(Equipment* e) {
	inventory.push_back(e);
} 

std::list<Stat> Player::getStats() {
	return stats;
}

std::vector<Equipment*> Player::getEquipment() {
	return inventory;
}

void Player::equip(int index) {
  
}

int Player::attack() {
  for (auto& s : getStats()) {
    if (s.getStatName() == StatName::power) {
      return s.getStatValue();
    }
  }

  return 0;
}

std::ostream& operator<<(std::ostream& os, Player& p) {
 	for (auto s : p.getStats()) {
		os << s << "\n";
	}	

	return os;
}
