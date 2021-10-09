#include "StudentClass.hpp"
#include "grade.hpp"
#include "median.hpp"
#include <iostream>
#include <algorithm>

int num;

int main()
{
	std::vector<Student_info> students;
	Student_info	recod;
	std::string::size_type maxlen = 0;

	// read data
	while (recod.read(std::cin))
	{
		maxlen = std::max(maxlen, recod.name().size());
		students.push_back(recod);
	}
	// sort students by name
	sort(students.begin(), students.end(), compare);

	// write names and grades
	std::vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end())
	{
		std::cout << iter->name() + " " << std::string(maxlen - iter->name().size(), ' ')
		<< iter->grade() << std::endl;
		iter++;
	}
	std::cout << students[0].finalgade << std::endl;
	return 0;
}
