#ifndef STUDENT_CLASS_777_HPP
#define STUDENT_CLASS_777_HPP

#include <vector>
#include <string>
#include <istream>

class Student_info
{
	private:
	//implementation goes here
		std::string			n;
		double midterm,		final;
		std::vector<double>	homework;

	public:
		double finalgade;
	//interface goes here
		Student_info();                 // construct an empty Student_info object
		Student_info(std::istream&);   // construct one by reading a stream
		double			grade();
		std::istream	&read(std::istream &); //added
			//	const  on the declaration of grade  is a promise that calling the grade
			//  function will not change any of the data members of
			//the Student_info  object
		std::string name() const { return n; } // gives users access to name but readonly;
		// we defined mem funcs outside the class definition
		// name() is an accessor function that allow easy access to hidden data
		// accessor should be provided only when they are part of the abstract interface
		// our abstraction is that of a student and a corresponding  grade.
		//a student name is part of out abstruction in contrast with other data..
		bool valid() const { return !homework.empty(); }
		// provide users with a method to test if the student object is valid to call grade
		// to avoid apotential exception
		// as before
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

#endif
