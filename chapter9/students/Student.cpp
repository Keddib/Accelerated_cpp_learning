#include "Student.hpp"
#include "grade.hpp"
#include <string>
#include <istream>

Student::Student(): midterm(0), final(0) {}
Student::Student(std::istream& is) { read(is); }

std::istream& Student::read(std::istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

double Student::grade()
{
	return ::grade(midterm, final);
}

bool compare(const Student& x, const Student& y)
{
	return (x.is_passed() || y.is_passed());
}
