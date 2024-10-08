#ifndef SWORDFACTORY_HPP
#define SWORDFACTORY_HPP

#include "../Sword.hpp"
#include "WeaponFactory.hpp"

class SwordFactory : public WeaponFactory {
public:
  SwordFactory();
  std::list<Stat> getSpecificStat(int stage) override;
  Equipment* createItem(int stage) override;
};

#endif //SWORDFACTORY_HPP
