#ifndef SWORDFACTORY_HPP
#define SWORDFACTORY_HPP

#include "../Sword.hpp"
#include "WeaponFactory.hpp"

class SwordFactory : public WeaponFactory {
public:
  inline SwordFactory() :WeaponFactory() {}
  Equipment* createItem(int stage) override;
};

#endif //SWORDFACTORY_HPP
