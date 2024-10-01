#ifndef STAGE_HPP
#define STAGE_HPP

#include <list>
#include <iostream>

#include "Ennemy.hpp"

class Stage {
private:
  std::list<Ennemy*> backLine;
  std::list<Ennemy*> frontLine;
public:
  Stage();
  Stage(std::list<Ennemy*> frontLine, std::list<Ennemy*> backLine);
  std::list<Ennemy*> getBackLine();
  std::list<Ennemy*> getFrontLine();
  std::list<Ennemy*> getEnnemies();
};

std::ostream& operator<<(std::ostream& os, Stage s);

#endif //STAGE_HPP
