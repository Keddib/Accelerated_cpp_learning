#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>	

using namespace std;

bool is_palindrome(const string &s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}


bool	not_space(char c)
{
	return !isspace(c);
}

bool	space(char c)
{
	return isspace(c);
}

vector<string> ft_split(const string &s)
{
	vector<string> strs;
	typedef string::const_iterator iter;

	iter i = s.begin();
	while (i != s.end())
	{
		i = find_if(i, s.end(), not_space);

		iter j = find_if(i, s.end(), space);

		if (i != s.end())
			strs.push_back(string(i, j));
		i = j;
	}
	return strs;
}


int main()
{
	vector<string> s = ft_split("hello Khalid Are u OK :D");
	copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));
}
