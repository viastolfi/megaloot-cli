#include "SwordFactory.hpp"

SwordFactory::SwordFactory() 
  : WeaponFactory()
{}

Equipment* SwordFactory::createItem(int stage) {
  Rarity r = getRandomRarity(stage);
  std::list<Stat> base = getBaseStat(stage, r);
  std::list<Stat> specific = getSpecificStat(stage);
  
  if (!specific.empty()) {
    base.merge(specific);
  }

  return new Sword("s", "sword", r, base);
}

std::list<Stat> SwordFactory::getSpecificStat(int stage) {
  std::list<Stat> s;

  // No specific stat for Sword

  return s;
}
