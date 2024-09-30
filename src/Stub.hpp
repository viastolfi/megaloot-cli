#ifndef STUB_HPP
#define STUB_HPP

#include <vector>
#include <list>

#include "Player.hpp"
#include "Equipment.hpp"
#include "Sword.hpp"
#include "Bow.hpp"
#include "Ennemy.hpp"
#include "Zombie.hpp"

class Stub {
public:
	inline static Player* createBase() {
		std::vector<Equipment*> inv;

		Equipment* e = new Sword("Wodden Sword", "Its crap", {Stat(StatName::power, 3)});
		Equipment* e1 = new Sword("Gold Sword", "Its mid", {Stat(StatName::power, 23)});
		Equipment* e2 = new Sword("Diamond Sword", "Its good", {Stat(StatName::power, 42)});
		Equipment* e3 = new Sword("Legendary Sword", "Its wow", {Stat(StatName::power, 103)});
		Equipment* e4 = new Bow("Wodden Bow", "Its crap", {Stat(StatName::power, 13)});
		Equipment* e5 = new Bow("Gold Bow", "Its mid", {Stat(StatName::power, 23)});
		Equipment* e6 = new Bow("Diamond Bow", "Its good", {Stat(StatName::power, 46)});
		Equipment* e7 = new Bow("Legendary Bow", "Its wow", {Stat(StatName::power, 50)});
		
		inv.push_back(e);
		inv.push_back(e1);
		inv.push_back(e2);
		inv.push_back(e3);
		inv.push_back(e4);
		inv.push_back(e5);
		inv.push_back(e6);
		inv.push_back(e7);
	
		Player* p = new Player(inv, {Stat(StatName::hp, 50)});	
		return p;
	}

	inline static Ennemy* createEnnemy() {
		Ennemy* e = new Zombie({Stat(StatName::power, 10), Stat(StatName::hp, 50)});
		return e;
	}
};

#endif //STUB_HPP
