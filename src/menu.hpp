#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>

#include "Equipment.hpp"
#include "Player.hpp"

void displayMenu(Player* p, int selectedIndex) {
    system("clear");

		for(auto e : p->getEquipment()) {
			if (p->getEquipment().at(selectedIndex) == e) {
      	std::cout << "-> " << *e  << std::endl;
			}	else {
      	std::cout << "   " << *e  << std::endl;
			}
		}
}

void menuGetEquipmentInfo(Player* p, int selectedIndex) {
	system("clear");
	Equipment* e = p->getEquipment().at(selectedIndex);

	std::cout << "==================================\n"; 	
	std::cout << *e << "\n";
	std::cout << "Description : " << e->getDescription() << "\n";
	std::cout << "Rariry : " << e->getRarity() << "\n";
   
	std::cout << "Stats : " << "\n";
	for (auto s : e->getStats()) {
		std::cout << s.getStatName() << " : " << s.getStatValue() << "\n";
	}
	std::cout << "==================================" << "\n";
}


#endif //MENU_HPP
