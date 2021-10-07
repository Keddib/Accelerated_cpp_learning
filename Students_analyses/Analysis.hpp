#ifndef GUARD_Analysis_hpp
#define GUARD_Analysis_hpp

// Analysis.h header file

#include <iostream>
#include <string>
#include <vector>
#include "Student.hpp"
#include "median.hpp"

double grade_aux(const Student_info &s);
double median_analysis(const std::vector<Student_info> &students);
double average_analysis(const std::vector<Student_info> &students);
void	write_analysis(
				std::ostream &out,
				const std::string &name,
				double analysis(const std::vector<Student_info> &),
				const std::vector<Student_info> &did,
				const std::vector<Student_info> &didnt);

#endif
