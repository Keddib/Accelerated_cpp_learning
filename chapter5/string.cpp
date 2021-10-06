#include <vector>
#include <string>
#include <iostream>
#include <cctype>


using namespace std;

vector<string> ft_split(const string &s)
{
	vector<string> vec;

	typedef string::size_type str_size;
	str_size len = s.size();
	str_size i = 0;
	while (i != len)
	{
		//scape white spaces
		while (i != len && isspace(s[i]))
			i++;
		//find end of next word
		str_size j = i;
		while (j != len && !isspace(s[j]))
			j++;
		//if i != j we are sure that this range [i, j) doesnt contain any whitespace
		if (i != j)
		{
			//copystring from [i, j); // half open range
			vec.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return vec;
}
