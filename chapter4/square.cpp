#include <iostream>
#include <iomanip>
#include <vector>
#include <string>



int sqaure()
{
	int i = 0;

	while (i < 101)
	{
		std::cout << std::setw(4);
		std::cout << i  << " " << i * i << std::endl;
		i++;
	}
	return 0;
}



std::vector<std::string> get_words(std::istream &in)
{
	std::string s;
	std::vector <std::string> vec;
		while (in >> s)
	{
		vec.push_back(s);
	}
	return vec;
}


bool sNotFound(const std::vector<std::string>& v, const std::string s)
{
	std::vector <std::string>::size_type i = 0;
	std::vector <std::string>::size_type size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (s == v[i])
			return false;
	}
	return true;
}


int main()
{
	std::vector <std::string> vec;
	std::vector <std::string> dup;
	vec = get_words(std::cin);
	std::vector <std::string>::size_type size = vec.size();
	std::cout << size << std::endl;
	std::vector <std::string>::size_type i = 0;
	int found = 0;
	for (i = 0; i < size; i++)
	{
		if (vec[i] == vec[i + 1])
		{
			if (sNotFound(dup, vec[i]))
			{
				std::cout << vec[i] << std::endl;
				dup.push_back(vec[i]);
			}
		}
	}
	return 0;
}
