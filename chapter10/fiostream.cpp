#include <fstream>
#include <iostream>




int main(int argc, char **argv)
{
	int fail_count = 0;
	for(int i = 1; i < argc; i++)
	{
		std::fstream in(argv[i]);
		if (in){
			std::string s;
			while (getline(in, s))
				std::cout << s << std::endl;
		} else {
			std::cerr << "cannot open file" << argv[i] << std::endl;
			++fail_count;
		}
	}
	return fail_count;
}
