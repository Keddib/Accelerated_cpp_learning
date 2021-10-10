#include <iostream>


int *func()
{
	static int i = 100;
	return &i;
}

int main()
{
	int *i = func();
	std::cout << *i << std::endl;

	int *j = new int;
	*j = 7;

	delete j;
	std::cout << *j << std::endl;
	delete j;
	return 0;
}
