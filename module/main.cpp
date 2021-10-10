#include <iostream>
#include <cctype>

int foo()
{
	return 10;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUAD LOUAD LOUAD LOUAD LOUAD *" << std::endl;
		return (0);
	}
	for (int y = 1; y < argc; y++)
	{
		for (int i = 0; argv[y][i]; i++)
			std::cout << (char) toupper(argv[y][i]);
	}
	std::cout << std::endl;
	int (*fcnPtr)();
	std::cout << reinterpret_cast<void*>(foo) << std::endl;
	return (0);
}
