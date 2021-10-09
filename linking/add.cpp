#include <iostream>
#include "add.hpp"

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x(0);
	std::cin >> x;
	return x;
}
