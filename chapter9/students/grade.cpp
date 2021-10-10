#include <stdexcept>
#include <vector>
#include "grade.hpp"
// #include "StudentClass.hpp"

using std::domain_error;  using std::vector;

double grade(double midterm, double final)
{
	return  0.54 * midterm + 0.46 * final;
}
