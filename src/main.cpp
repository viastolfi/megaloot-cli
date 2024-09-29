#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "Equipment.hpp"
#include "Sword.hpp"
#include "Bow.hpp"

void setInputModeRaw(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);           
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);        
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

char readArrowKey() {
    char c;
    if (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == '\033') { 
            char seq[2];
            if (read(STDIN_FILENO, &seq, 2) == 2) {
                if (seq[0] == '[') {
                    switch (seq[1]) {
                        case 'A': return 'u';
                        case 'B': return 'd';
                        case 'C': return 'r';
                        case 'D': return 'l';
                    }
                }
            }
        }
				else return c;
    }
    return '\0';
}

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

void makeInventory(Equipment* inventory[5]) {
	for (int i = 0; i < 5; ++i) {
		if (i % 2 == 0) {
			Equipment* e = new Sword("s", "Sword");
			inventory[i] = e;	
		} else {
			Equipment* e = new Bow("b", "Bow");
			inventory[i] = e;
		}
	}	
}

int main(int argc, char** argv) {
		srand(static_cast<unsigned int>(time(0)));
		const int numItems = 5;
    Equipment* inventory[numItems];
		makeInventory(inventory);
    int selectedIndex = 0;

    setInputModeRaw(true);

    char input;
    while (true) {
        displayMenu(inventory, numItems, selectedIndex); 

        input = readArrowKey();

        if (input == 'u' && selectedIndex > 0) {
            --selectedIndex; 
        } 
				else if (input == 'd' && selectedIndex < numItems - 1) {
            ++selectedIndex;

        } 
				else if (input == 'r') {
					makeInventory(inventory);
				}
				else if (input == 'q') {
            break; 
        }
    }

    setInputModeRaw(false);

    return 0;
}
