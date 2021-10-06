#include <list>
#include <iostream>

using namespace std;


list<int> read_data(istream& in)
{
	int num;
	list<int> l;
	while (in >> num)
		l.push_back(num);
	return l;
}

list<int> extract_neg(list<int>& l)
{
	list<int> neg;
	list<int>::iterator iter= l.begin();
	while (iter != l.end())
	{
		if (*iter < 0)
		{
			neg.push_back(*iter);
			iter = l.erase(iter);
		}
		else
			++iter;
	}
	return neg;
}

int main()
{
	list<int> l;
	list<int> negative;

	l = read_data(cin);
	negative = 	extract_neg(l);
	std::copy(std::begin(l), std::end(l),std::ostream_iterator<int>(std::cout, ",  "));
	std::cout << std::endl;
	std::copy(std::begin(negative), std::end(negative), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}
