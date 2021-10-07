/// map example



#include <map>
#include <iostream>
#include <string>




int main()
{
	std::string s;
	std::map<int, std::string> count; // store each word and an associated counter


	count[2] = "hello";
	std::map<int, std::string>::iterator it = count.begin();
	std::cout << it->first << " " << it->second << std::endl;
	// read the input
	// while (std::cin >> s)
	// 	++count[s];

	// std::map<std::string, int>::iterator i = count.begin();

	// while (i != count.end())
	// {
	// 	std::cout << i->first << " " << i->second << std::endl;
	// 	i++;
	// }
	return 0;
}
