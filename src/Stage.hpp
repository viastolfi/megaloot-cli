#ifndef STAGE_HPP
#define STAGE_HPP

#include <vector>
#include <iostream>

#include "Ennemy.hpp"

class Stage {
private:
  std::vector<Ennemy*> backLine;
  std::vector<Ennemy*> frontLine;
public:
  Stage();
  Stage(std::vector<Ennemy*> frontLine, std::vector<Ennemy*> backLine);
  std::vector<Ennemy*> getBackLine();
  std::vector<Ennemy*> getFrontLine();
  void removeEnnemy(Ennemy* e);
};

std::ostream& operator<<(std::ostream& os, Stage s);

#endif //STAGE_HPP
