#include "WeaponFactory.hpp"

WeaponFactory::WeaponFactory()
  :EquipmentFactory()
{}

std::list<Stat> WeaponFactory::getBaseStat(int stage) {
  std::list<Stat> s;

  s.push_back(Stat(StatName::power, stage));
  return s;
}
