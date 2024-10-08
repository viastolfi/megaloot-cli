#ifndef WEAPONFACTORY_HPP
#define WEAPONFACTORY_HPP

#include <list>

#include "EquipmentFactory.hpp"
#include "../Stat.hpp"

class WeaponFactory : public EquipmentFactory {
public: 
  WeaponFactory();
  std::list<Stat> getBaseStat(int stage) override;
  virtual ~WeaponFactory() {}
};

#endif //WEAPONFACTORY_HPP
