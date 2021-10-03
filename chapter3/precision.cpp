#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
     << 0.2 * 10 + 0.4 * 120 + 0.4 * 12 / 4
     << setprecision(prec) << endl;
	return 0;
}
