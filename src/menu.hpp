#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>

#include "Equipment.hpp"

void displayMenu(Equipment** items, int numItems, int selectedIndex) {
    system("clear");
    for (int i = 0; i < numItems; ++i) {
        if (i == selectedIndex) {
            std::cout << "-> " << *items[i] << std::endl;
        } else {
            std::cout << "   " << *items[i] << std::endl;
        }
    }
}

void menuGetEquipmentInfo(Equipment** items, int numItems, int selectedIndex) {
	system("clear");
	Equipment* e = items[selectedIndex];

	std::cout << "==================================\n"; 	
	std::cout << *e << "\n";
	std::cout << "Description : " << e->getDescription() << "\n";
	std::cout << "Rariry : " << e->getRarity() << "\n";
	std::cout << "==================================" << "\n";
}


#endif //MENU_HPP
