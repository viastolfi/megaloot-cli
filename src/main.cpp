#include <iostream>

#include "Equipment.hpp"

int main(int argc, char** argv) {
		Equipment* e = new Equipment("sword", "That's a cool sword");
		std::cout << *e << std::endl;
    return 0;
}
