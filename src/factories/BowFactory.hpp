#ifndef BOWFACTORY_HPP
#define BOWFACTORY_HPP

#include "WeaponFactory.hpp"
#include "../Bow.hpp"

class BowFactory: public WeaponFactory {
public:
  BowFactory();
  std::list<Stat> getSpecificStat(int stage) override;
  Equipment* createItem(int stage) override;
};

#endif // BOWFACTORY_HPP
