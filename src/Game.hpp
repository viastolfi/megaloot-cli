#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Stage.hpp"
#include "Sword.hpp"
#include "Bow.hpp"
#include "Zombie.hpp"
#include "EquipmentFactory.hpp"

class Game {
 private:
   int actualStageNumber = 0;
   Stage stage;
   Player* player;
 public:
   Game(Player* player);
   void generateNewItems();
   Player* getPlayer();
   Stage getStage();
   void ennemiesAttack();
   int getStageNumber();
   void playerAttack(Ennemy* e);
   void generateNewStage();
   void getLoot();
   void setStageNumber(int s);
};

#endif //GAME_HPP
