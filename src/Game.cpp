#include "Game.hpp"

Game::Game(Player* player)
  :player(player)
{}

void Game::start() {
  player->addEquipment(new Sword("basic sword", "It's a basic sword", {Stat(StatName::power, 10)}));
  player->addEquipment(new Bow("basic bow", "It's a basic bow", {Stat(StatName::power, 8)}));

  generateNewStage();
}

void Game::generateNewStage() {
  Ennemy* fl = new Zombie({Stat(StatName::power, 10), Stat(StatName::hp, 7)});
  Ennemy* bl = new Zombie({Stat(StatName::power, 6), Stat(StatName::hp, 10)});

  std::list<Ennemy*> frl = {fl};
  std::list<Ennemy*> bal = {bl};

  stage = Stage(frl, bal);
}

void Game::playerAttack(Ennemy* e) {
  int damage = player->attack();
  
  std::cout << damage << std::endl; 
}

void Game::getLoot() {
  //Equipment* sword = new Sword ("medium sword", "It's a medium sword", {Stat(StatName::power, 10)}); 
  //Equipment* bow = new Bow("medium bow", "It's a medium bow", {Stat(StatName::power, 8)});

  // TODO : implement
}

Stage Game::getStage() {
  return stage;
}

Player* Game::getPlayer() {
  return player;
}
