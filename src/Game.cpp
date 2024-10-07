#include "Game.hpp"

Game::Game(Player* player)
  :player(player)
{}

void Game::generateNewStage() {
  Ennemy* fl = new Zombie({new Stat(StatName::power, 10),new Stat(StatName::hp, 7)});
  Ennemy* bl = new Zombie({new Stat(StatName::power, 6),new Stat(StatName::hp, 10)});

  std::vector<Ennemy*> frl = {fl};
  std::vector<Ennemy*> bal = {bl};

  stage = Stage(frl, bal);
  actualStageNumber++;
}

void Game::generateNewItems() {
  EquipmentFactory* f = new SwordFactory();
  Equipment* e = f->createItem(actualStageNumber);
  delete f;
  std::cout << *e << std::endl;
  /*
  for (int i = 0; i < 4; ++i) {
    Equipment* e = EquipmentFactory::generateRandomItem(actualStageNumber);
    std::cout << *e << std::endl;
    for (auto s : e->getStats()) {
      std::cout << s << " ";
    }
    std::cout << "\n";
    player->addEquipment(e);
    //player->addEquipment(EquipmentFactory::generateRandomItem(actualStageNumber));
  } 
  */
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

void Game::setStageNumber(int s) {
  actualStageNumber = s;
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
