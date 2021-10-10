#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>

bool compare(int num)
{
	return num > 0;
}

bool com(int num)
{
	return num < 0;
}

std::vector<int> myfind(std::vector<int>::const_iterator b,
						std::vector<int>::const_iterator e,
						bool (*func)(int num) = compare)
{
	std::vector<int> vec;
	while (b != e)
	{
		if (func(*b))
			vec.push_back(*b);
		b++;
	}
	return vec;
}


int main()
{
	// bool (*com)(int);

	std::vector<int> vec(10, -5);
	for(int i = 0; i < 10; i++)
		vec.push_back(i);
	std::vector<int> neg;
	neg = myfind(vec.begin(), vec.end());
	std::copy(neg.begin(), neg.end(), std::ostream_iterator<int>(std::cout, " "));
	neg = myfind(vec.begin(), vec.end(), com);
	std::cout << std::endl;
	std::copy(neg.begin(), neg.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
