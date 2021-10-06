
#ifndef GUARD_grade_hpp
#define GUARD_grade_hpp

//  grade.h

#include <vector>
#include "Student.hpp"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif
