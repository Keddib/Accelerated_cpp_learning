#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <list>


bool	not_space(char c)
{
	return !isspace(c);
}

bool	space(char c)
{
	return isspace(c);
}

template<class Out>
void ft_split(const std::string &s, Out iter)
{
	typedef std::string::const_iterator s_iter;

	s_iter i = s.begin();
	while (i != s.end())
	{
		// ignore leading blanks
		i = find_if(i, s.end(), not_space);
		// find end of next word
		s_iter j = find_if(i, s.end(), space);
		// copy the characters in [i, j)
		if (i != s.end())
			*iter++ = std::string(i, j);
		i = j;
	}
}


int main()
{
	std::string s;
	std::vector<std::string> s_v(10);
	std::list<std::string> s_l(10);

	ft_split("khaid eddib hello 1337 42 Iam doing well", s_v.begin());
	ft_split("khaid eddib hello 1337 42 Iam doing well", s_l.begin());
	copy(s_v.begin(), s_v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	copy(s_l.begin(), s_l.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	// while (getline(std::cin, s))
    //     ft_split(s, std::ostream_iterator<std::string>(std::cout, "\n"));
	return 0;
}
