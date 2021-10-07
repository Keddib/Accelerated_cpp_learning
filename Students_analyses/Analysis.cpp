#include <string>
#include <vector>
#include <cctype>
#include <numeric>
#include "Student.hpp"
#include "grade.hpp"
#include "median.hpp"


using namespace std;

double average(const vector<double> &grades)
{
	return accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

double grade_aux(const Student_info &s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}


double average_grade(const Student_info &s)
{
	return grade(s.midterm, s.final, average(s.homework));
}


// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double median_analysis(const vector<Student_info> &students)
{
	vector<double> grades;

	transform(
		//grade is overloaded the compiler doesn't know
		//wish one because of args. And grade throw expetion in case of no homework
		// students.begin(), students.end(), back_inserter(grades), grade
		// replace it with a auxiliry func grade_aux
		students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info> &students)
{
	vector<double> grades;
	transform(
		students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info> &students)
{
	vector<double> grades;
	transform(
		students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void	write_analysis(
				ostream &out,
				const string &name,
				double analysis(const vector<Student_info> &),
				const vector<Student_info> &did,
				const vector<Student_info> &didnt)
{
	out << name <<": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}
