#ifndef ENNEMY_HPP
#define ENNEMY_HPP

#include <list>
#include <iostream>

#include "Stat.hpp"

class Ennemy {
private: 
	std::list<Stat*> stats;
public:
  inline Ennemy(std::list<Stat*> stats):stats{stats} {}

	virtual int attack() = 0;
	virtual void print(std::ostream& os) = 0;
  virtual int getDamaged(int damage) = 0;

	inline std::list<Stat*> getStats() { return stats; }
	inline void addStat(Stat* stat) { stats.push_back(stat); }
  virtual ~Ennemy() {
    if (!stats.empty()) {
      for (auto s : stats) {
        delete s;
      } 
    } 
  };
};

inline std::ostream& operator<<(std::ostream& os, Ennemy& e) {
	e.print(os);
	return os;
}

#endif //ENNEMY_HPP
