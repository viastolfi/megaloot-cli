#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "Stat.hpp"
#include "StatName.hpp"
#include "menu.hpp"
#include "Equipment.hpp"
#include "Sword.hpp"
#include "Bow.hpp"
#include "Stub.hpp"
#include "Player.hpp"
#include "Ennemy.hpp"
#include "Game.hpp"

typedef void (*menuFunction) (Player* p, int selectedIndex);

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
                    }
                }
            }
        }
				else return c;
    }
    return '\0';
}

int main(int argc, char** argv) {
		srand(static_cast<unsigned int>(time(0)));

		if (argc > 1) {
      if (std::string(argv[1]) == "dev") {
        Game* game = new Game(new Player({new Stat(StatName::hp, 20), new Stat(StatName::power, 0)}));
        game->start();
        std::cout << "Game is starting !\n";
        std::cout << "\n=========PLAYER=============\n";
        std::cout << *(game->getPlayer()) << "\n";
        std::cout << "=========EQUIPMENT=============\n";
        for (auto e : game->getPlayer()->getEquipment()) {
          std::cout << *e << "\n";
        }
        std::cout << "=========STAGE=============\n";
        std::cout << game->getStage() << "\n";

        std::cout << "=========EQUIP FIRST WEAPON=============\n";
        game->getPlayer()->equipWeapon(0);
        std::cout << "Weapon equiped, new Player stats\n";
        std::cout << *(game->getPlayer()) << "\n";

        std::cout << "=========FIRST ROUND=============\n";
        std::cout << "Player attack\n";
        game->playerAttack(game->getStage().getFrontLine().at(0));
        std::cout << "=========PLAYER ACTIONS FINISH=============\n";
        std::cout << "Stage after round :\n";
        std::cout << game->getStage();
        std::cout << "Ennemies attack\n";
        game->ennemiesAttack();
        std::cout << "=========ROUND FINISH=============\n";
        std::cout << "Player after round :\n";
        std::cout << *(game->getPlayer()) << "\n";
        std::cout << "=========SECOND ROUND=============\n";
        std::cout << "Player attack\n";
        game->playerAttack(game->getStage().getBackLine().at(0));
        std::cout << "Stage after round :\n";
        std::cout << game->getStage();
      }
      if (std::string(argv[1]) == "loop") {
        Game* game = new Game(new Player({new Stat(StatName::hp, 20), new Stat(StatName::power, 0)}));
        game->start();

        while(game->getStageNumber() != 2 && game->getPlayer()->getHp() > 0) {
          game->getPlayer()->showInventory();
          char c = ' ';
          while (c != 'q') {
            std::cout << "Choose Equipment to equip\n";
            std::cin >> c;
            game->getPlayer()->equipItem(c - '0');
            std::cout << "You Equiped item number : " << c << "\n";
            game->getPlayer()->showInventory();
          }
        }
      }
    } else {
			std::cout << "Not implemented yet" << std::endl;
			/*
    	int selectedIndex = 0;
			int actualMenu = 0;
			std::vector<menuFunction> functions = { displayMenu, };

    	setInputModeRaw(true);
    	char input;

    	while (true) {
				functions[actualMenu](player, selectedIndex);
        input = readArrowKey();

        if (input == 'u' && selectedIndex > 0) {
            --selectedIndex; 
        } 
				else if (input == 'd' && selectedIndex < player->getEquipment().size() - 1) {
            ++selectedIndex;

        } 
				else if (input == ' ') {
					functions.push_back(menuGetEquipmentInfo);
					actualMenu++;
				}
				else if (input == 'q') {
						actualMenu--;
						if(actualMenu == -1) break;
						else functions.pop_back();
        } else {
					std::cout << input << std::endl;
				}
    	}
		
    	setInputModeRaw(false);
			*/
		}
    return 0;
}
