#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include "grade.hpp"
#include "Student.hpp"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}


// separate passing and failing student records: first try
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info>	fail;
	list<Student_info>::iterator	iter = student.begin();

	while (iter != student.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	 return fail;
}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name
	// read and store all the students data.
	// Invariant:  students contains all the student records read so far
	//   maxlen contains the length of the longest name in students
	while (read(cin, record)) {
		// find length of longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	vector<Student_info>::const_iterator iter = student.begin();
	vector<Student_info>::const_iterator end = student.end();

	// write the names and grades
	while (iter != end) {
		// write the name, padded on the right to maxlen + 1 characters
		cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');
		// compute and write the grade
		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
		iter++;
	}
	std::vector<int>::iterator it;
	return 0;
}
