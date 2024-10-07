#include "SwordFactory.hpp"

Equipment* SwordFactory::createItem(int stage) {
  Rarity r = getRandomRarity(stage);
  return new Sword("s", "sword", r);
}
