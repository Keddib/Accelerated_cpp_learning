#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main()
{
	int number;
	std::vector <int> vi;
	std::vector <int>::size_type size;
	std::cout  << "Please enter a set of numbers ";
	while (std::cin >> number)
	{
		n_elements++;
		vi.push_back(number);
	}

	std::cout << std::endl;
	size = vi.size();
	if (size == 0)
	{
		std::cout << "PLEASE ENTER SOME VALUES" << std::endl;
		return 1;
	}
	sort(vi.begin(), vi.end());

	int Q1, Q2, Q3;
	int mid = size / 2;
	int is_odd, mid2;
	is_odd = mid % 2;

	Q2 = is_odd ? vi[mid] : (vi[mid] + vi[mid - 1]) / 2;

	mid2 = is_odd ? mid / 2 : (mid - 1) / 2;
	is_odd = mid2 % 2;

	Q1 = is_odd ? vi[mid2] : (vi[mid2] + vi[mid2 - 1]) / 2;

	mid2 = size - mid;
	is_odd = mid2 % 2;
	mid = mid + mid2 / 2;


	std::cout << "Q1 " << Q1 << " Q2 " << Q2 << " Q3 " << Q3 << std::endl;
	return 0;
}
