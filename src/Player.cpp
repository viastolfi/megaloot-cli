#include "Player.hpp"

Player::Player()
  :stats{}, inventory{}, equipedWeapon{nullptr}
{}

Player::Player(std::list<Stat*> stats)
  :stats{stats}, inventory{}, equipedWeapon{nullptr}
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

void Player::showInventory() {
  std::cout << "=========EQUIPED ITEMS=========\n";
  if (equipedWeapon) {
    std::cout << "E " << *equipedWeapon << "\n";
  } else {
    std::cout << "No items equiped\n";
  }
  std::cout << "=========SHOW INVENTORY=========\n";
  for (auto e : inventory) {
    std::cout << *e << "\n"; 
  }
}

int Player::getHp() {
  for (auto s : stats) {
    if (s->getStatName() == StatName::hp) {
      return s->getStatValue();
    }
  } 

  return 0;
}
 
void Player::getDamaged(int damage) {
  for (auto s : stats) {
    if (s->getStatName() == StatName::hp) {
      s->setStatValue(s->getStatValue() - damage);
    } 
  }
}

std::list<Stat*> Player::getStats() {
	return stats;
}

std::vector<Equipment*> Player::getEquipment() {
	return inventory;
}

void Player::equipItem(int index) {
  if (index >= inventory.size()) {
    std::cout << "Index : " << index << " out of range\n";
    return;
  }
  if (Weapon* tmp = dynamic_cast<Weapon*>(inventory[index])) {
    equipWeapon(index);     
  }
  else {
    std::cout << "Not implemented yet\n";
  }
}

void Player::equipWeapon(int index) {
  // NOTE : Possible futur error. Use dynamic_cast for better safety
  Weapon* tmp = nullptr;
  if (equipedWeapon) {
    tmp = equipedWeapon; 
  }
  equipedWeapon = static_cast<Weapon*>(inventory[index]);
  inventory.erase(inventory.begin() + index);

  if (tmp) {
    inventory.push_back(tmp);
  }

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
