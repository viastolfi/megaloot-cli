#ifndef WEAPONFACTORY_HPP
#define WEAPONFACTORY_HPP

#include <cstdlib>
#include <ctime>
#include <list>

#include "EquipmentFactory.hpp"
#include "../Stat.hpp"

class WeaponFactory : public EquipmentFactory {
public: 
  WeaponFactory();
  std::list<Stat> getBaseStat(int stage, Rarity r) override;
  virtual ~WeaponFactory() {}
};

#endif //WEAPONFACTORY_HPP
