#include <iostream>

#include "Pointer.h"
#include "Pointers.h"
#include "Pointing.h"

int main()
{
    std::cout << "Which class method would you like to execute?";
	std::cout << "\n1. Pointer\n2. Pointers\n3. Pointing\n";
	
	int choice;
	std::cin >> choice;
	
	switch (choice) {
		case 1:
			Pointer::execute();
			break;
		case 2:
			Pointers::execute();
			break;
		case 3:
			Pointing::execute();
			break;
		default:
			std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
			break;
	}
	return 0;
}
