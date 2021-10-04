#include <iostream>
using namespace std;

void Twice(int&, int&);			// prototype

int main()
{
   int x = 5, y = 8;

   cout << "Initial values of variables:\n";
   cout << "\tx = " << x << "\ty = " << y << '\n';

   cout << "Calling the function Twice(x,y)\n";
   Twice(x,y);				// what will this do?

   cout << "The new values of x and y are:\n";
   cout << "\tx = " << x << "\ty = " << y << '\n';
   cout << "Goodbye!\n";
}

void Twice(int &a, int &b)
// WHAT does this function do?
{
   a *= 2;
   b *= 2;
}
