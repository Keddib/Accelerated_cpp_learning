#ifndef STUDENT_88_HPP
#define STUDENT_88_HPP

#include <string>
#include <istream>

class Student{
	private:
		std::string n;
		double midterm, final;
		bool passed;
	public:
		Student();
		Student(std::istream &);
		double			grade();
		std::istream	&read(std::istream &);
		bool	is_passed() const {return passed;};
		std::string name() const { return n; }
};

bool compare(const Student& x, const Student& y);

#endif
