#include <stdexcept>
#include <vector>
#include "grade.hpp"
#include "median.hpp"
// #include "StudentClass.hpp"

using std::domain_error;  using std::vector;

double grade(double midterm, double final, double homework)
{
	return  0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
