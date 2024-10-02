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
  Ennemy* fl = new Zombie({new Stat(StatName::power, 10),new Stat(StatName::hp, 7)});
  Ennemy* bl = new Zombie({new Stat(StatName::power, 6),new Stat(StatName::hp, 10)});

  std::vector<Ennemy*> frl = {fl};
  std::vector<Ennemy*> bal = {bl};

  stage = Stage(frl, bal);
  actualStageNumber++;
}

int Game::getStageNumber() {
  return actualStageNumber;
}

void Game::playerAttack(Ennemy* e) {
  int damage = player->attack();

  int lifeAfterAttack = e->getDamaged(damage);
  if (lifeAfterAttack <= 0) {
    stage.removeEnnemy(e);
  }
}

void Game::ennemiesAttack() {
  int damage = 0;
  for (auto e: stage.getFrontLine()) {
    damage+=e->attack();
  }
  for (auto e: stage.getBackLine()) {
    damage+=e->attack();
  }

  player->getDamaged(damage);
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
