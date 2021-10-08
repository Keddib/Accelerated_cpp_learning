#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	// we can use contructor to make plce for 10 values , but what if you don't know how many value we need to copy
	// do the best way is to use iterator adaptor so we can make aditional space each time we need to instert a value

	copy(u.begin(), u.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(u.begin(), u.end(), back_inserter(v));

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	std::string str = "Hello World!";
	std::vector<std::string> vec(10,str);
	string a = accumulate(vec.begin(), vec.end(), std::string(""));
	cout << a << endl;

	return 0;
}
