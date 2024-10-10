#include "WeaponFactory.hpp"

WeaponFactory::WeaponFactory()
  :EquipmentFactory()
{}

std::list<Stat> WeaponFactory::getBaseStat(int stage, Rarity r) {
  std::list<Stat> s;
  int min_s = (10 + stage * 2) * (static_cast<int>(r.getName()) + 1);
  int max_s = (13 + stage * 2) * (static_cast<int>(r.getName()) + 1);

  int randNum = rand()%(max_s-min_s + 1) + min_s;  

  s.push_back(Stat(StatName::power, randNum));
  return s;
}
