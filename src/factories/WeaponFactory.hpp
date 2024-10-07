#ifndef WEAPONFACTORY_HPP
#define WEAPONFACTORY_HPP

#include "EquipmentFactory.hpp"

class WeaponFactory : public EquipmentFactory {
public: 
  inline WeaponFactory() :EquipmentFactory() {}
  virtual Equipment* createItem(int stage) = 0;
  virtual ~WeaponFactory() {}
};

#endif //WEAPONFACTORY_HPP
