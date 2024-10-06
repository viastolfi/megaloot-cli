#ifndef EQUIPMENTFACTORY_HPP
#define EQUIPMENTFACTORY_HPP

#include <random>
#include <iostream>

#include "Rarity.hpp"
#include "Sword.hpp"

class EquipmentFactory {
  public:
    inline static Equipment* generateRandomItem(int stage) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);

        int randomItem = dis(gen); 

        Rarity r = getRandomRarity(stage);

        Equipment * s = new Sword("S", "s", r);
        std::cout << *s << std::endl;

        /*
        switch (randomItem) {
          case 0: return new Sword("Sword", "Basic Sword", {Stat(StatName::power, 10)});
          case 1: return new Bow("Bow", "Basic Bow", {Stat(StatName::power, 8)});
          default: return nullptr;
        }
        calculateRarityWeights(stage);
        */
    }

  inline static std::vector<double> calculateRarityWeights(int stage) {
    double commonWeight = 70.0;  
    double rareWeight = 20.0;   
    double epicWeight = 9.0;   
    double legendaryWeight = 1.0;

    if (stage > 0) {
        commonWeight = std::max(0.0, commonWeight - stage * 0.7);
        rareWeight = std::max(0.0, rareWeight - stage * 0.2);
        epicWeight = std::min(100.0, epicWeight + stage * 0.5);
        legendaryWeight = std::min(100.0, legendaryWeight + stage * 0.5);
    }

    double totalWeight = commonWeight + rareWeight + epicWeight + legendaryWeight;

    return {
        commonWeight / totalWeight,
        rareWeight / totalWeight,
        epicWeight / totalWeight,
        legendaryWeight / totalWeight
    };
  }

  inline static Rarity getRandomRarity(int stage) {
    auto weights = calculateRarityWeights(stage);

    double randomValue = static_cast<double>(rand()) / RAND_MAX;
    double cummulativeValue = 0.0;

    for(int i = 0; i < 4; i++) {
      cummulativeValue += weights[i]; 
      if (randomValue <= cummulativeValue) {
        return Rarity(static_cast<RarityName>(i)); 
      }
    }

    return Rarity(RarityName::common);
  }
};

#endif //EQUIPMENTFACTORY_HPP
