#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Stage.hpp"
#include "Sword.hpp"
#include "Bow.hpp"
#include "Zombie.hpp"

class Game {
 private:
   int actualStageNumber = 0;
   Stage stage;
   Player* player;
 public:
   Game(Player* player);
   void start();
   Player* getPlayer();
   Stage getStage();
   void generateNewStage();
   void getLoot();
};

#endif //GAME_HPP
