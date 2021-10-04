#include <iostream>
#include <string>
// #include <vector>
// #include <algorithm>
// #include <stdio.h>


using namespace std;

int main ()
{
	cout << "ENTER SOME WORDS" << endl;
	string s;
	string::size_type min, max, size;
	min = 0;
	max = 0;
	cin >> s;
	min = s.size();
	max = s.size();
	while (cin >> s)
	{
		size = s.size();
		if (size < min)
			min = size;
		else if (size > max)
			max = size;
	}
	cout << min << " " << max << endl;
	return 0;
}
