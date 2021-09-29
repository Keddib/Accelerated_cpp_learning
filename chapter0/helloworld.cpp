// a small c++ program
#include <iostream>

using namespace std;

namespace hajar
{
	char s[15] = "khalid Eddib";
	void	hello(int a)
	{
		cout << s << endl << a << "\n";
	}
}

int main()
{
	hajar::hello(50);
	// cout << endl;
	// cout << hajar::s << endl;
	// cout << endl;
	return 0;
}
