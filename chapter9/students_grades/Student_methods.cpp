
#include "StudentClass.hpp"
#include <iostream>
#include "grade.hpp"

Student_info::Student_info(): midterm(0), final(0) {}
Student_info::Student_info(std::istream& is) { read(is); }

std::istream& Student_info::read(std::istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

double Student_info::grade()
{
	finalgade = ::grade(midterm, final, homework);
	return finalgade;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear() ;
		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}
