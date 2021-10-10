
#include "Student.hpp"


#include "grade.hpp"

#include <string>

#include <vector>

#include <iostream>



int main()
{
	std::vector<Student> students;
	Student each;
	std::string::size_type maxlen = 0;

	while (each.read(std::cin))
	{
		maxlen = std::max(maxlen, each.name().size());
		students.push_back(each);
	}

	std::sort(students.begin(), students.end(), compare);

	std::vector<Student>::iterator iter = students.begin();
	while (iter != students.end())
	{
		char c = 'F';
		if (iter->is_passed())
			c = 'P';
		std::cout << iter->name() + std::string(maxlen  - iter->name().size(), ' ') << c << std::endl;
		iter++;
	}
	return 0;
}
