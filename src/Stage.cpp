#include "Stage.hpp"

Stage::Stage()
  :backLine{}, frontLine{}
{}

Stage::Stage(std::vector<Ennemy*> frontLine, std::vector<Ennemy*> backLine)
  :backLine{backLine}, frontLine{frontLine}
 {}

std::vector<Ennemy*> Stage::getBackLine() {
  return backLine;
}

std::vector<Ennemy*> Stage::getFrontLine() {
  return frontLine;
}

void Stage::removeEnnemy(Ennemy* e) {
  for (int i = 0; i < getFrontLine().size(); ++i) {
    if (e == frontLine.at(i)) {
      if (frontLine.size() == 1) {
        frontLine.clear();
      }
      else {
        frontLine.erase(getFrontLine().begin() + i); 
      }
    }
  }
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
