#include <iostream>
#include <string>


using namespace std;

int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";
    // read the name
    string name = "khalid";
    // cin >> name;
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // we have to rewrite this part...
	cout << endl;

	int pad = 1;
	// cout << "Please enter the padding: ";
	// cin >> pad;
	// cout << endl;
	const int rows = pad * 2 + 3;
	const string::size_type c = greeting.size() + pad * 2 + 2;
	string spaces(c - 2, ' ');


	for (int r = 0; r < rows; r++)
	{
		string::size_type x = 0;
		while (x < c)
		{
			if (r == pad + 1 && x == pad + 1)
			{
				cout << greeting;
				x += greeting.size();
			}
			if (r == 0 || r == rows - 1 || x == 0 || x == c - 1)
			{
				cout << "*";
				x++;
			}
			else
			{
				if (r == pad + 1)
				{
					cout << " ";
					x++;
				}
				else
				{
					cout << spaces;
					x+= spaces.size();
				}
			}
		}
		cout << endl;
	}
	return 0;
}
