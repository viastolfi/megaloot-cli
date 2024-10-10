#include "BowFactory.hpp"

BowFactory::BowFactory()
  : WeaponFactory()
{}

Equipment* BowFactory::createItem(int stage) {
    Rarity r = getRandomRarity(stage);
    std::list<Stat> base = getBaseStat(stage, r);
    std::list<Stat> specific = getSpecificStat(stage);
    
    if (!specific.empty()) {
      base.merge(specific); 
    }

    return new Bow("bow", "Bow", r, base);
}

std::list<Stat> BowFactory::getSpecificStat(int stage) {
  std::list<Stat> s;

  s.push_back(Stat(StatName::hp, 13));

  return s;
}
