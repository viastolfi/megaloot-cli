#include "Stage.hpp"

Stage::Stage()
  :backLine{}, frontLine{}
{}

Stage::Stage(std::list<Ennemy*> frontLine, std::list<Ennemy*> backLine)
  :backLine{backLine}, frontLine{frontLine}
 {}

std::list<Ennemy*> Stage::getBackLine() {
  return backLine;
}

std::list<Ennemy*> Stage::getFrontLine() {
  return frontLine;
}

std::list<Ennemy*> Stage::getEnnemies() {
  std::list<Ennemy*> cl = getFrontLine();
  cl.merge(getBackLine());
  return cl;
}

std::ostream& operator<<(std::ostream& os, Stage s) {
  os << "Front Line : ";
  for (auto e : s.getFrontLine()) {
    os << "\n" << *e;
  }
  os << "\nBack Line : ";
  for (auto e : s.getBackLine()) {
    os << "\n" << *e;
  }
  return os;
}
