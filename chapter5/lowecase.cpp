#include <string>
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	if (argc < 2)
		return 1;
	int i = 1;
	while (argv[i])
	{
		cout << argv[i] << endl;
		int x = 0;
		while (argv[i][x])
		{
			argv[i][x] = toupper(argv[i][x]);
			x++;
		}
		cout << argv[i] << endl;
		i++;
	}
}
