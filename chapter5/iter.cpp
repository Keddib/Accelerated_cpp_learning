#include <vector>
#include <iostream>

using namespace std;

int  main()
{
	vector<int> vec;

	for(int i = 0; i < 11; i++)
		vec.push_back(i * 2);
	vector<int>::iterator iter;

	iter = vec.begin();

	cout << *iter << endl;

	iter = vec.erase(iter);

	cout << *iter << endl;
	return 0;
}
