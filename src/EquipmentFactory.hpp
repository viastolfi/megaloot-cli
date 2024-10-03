#ifndef EQUIPMENTFACTORY_HPP
#define EQUIPMENTFACTORY_HPP

#include <random>

class EquipmentFactory {
  public:
    inline static Equipment* generateRandomItem() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        int randomItem = dis(gen); 

        switch (randomItem) {
          case 0: return new Sword("Sword", "Basic Sword", {Stat(StatName::power, 10)});
          case 1: return new Bow("Bow", "Basic Bow", {Stat(StatName::power, 8)});
          default: return nullptr;
        }
    }
};

#endif //EQUIPMENTFACTORY_HPP
