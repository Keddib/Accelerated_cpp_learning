#include <iostream>


using namespace std;

int main ()
{
	int sqware;
	int triangle;
	int recx;
	int recy;

	cout << "enter square ";
	cin >> sqware;
	cout << "enter triangle ";
	cin >> triangle;
	cout << "enter rectangle x ";
	cin >> recx;
	cout << "enter rectangle y ";
	cin >> recy;

	cout << endl;
	for (int y = 0; y < sqware; y++)
	{
		for(int x = 0; x < sqware * 2; x++)
			cout << "*";
		cout << endl;
	}
	cout << endl;
	for (int y = 0; y < recy; y++)
	{
		for(int x = 0; x < recx * 2; x++)
			cout << "*";
		cout << endl;
	}
	cout << endl;

	int l = triangle * 2;
	int start = 0;
	int t = 0;
	for (int y = 0; y < triangle; y++)
	{
		for (int x = 0; x < l; x++)
		{
			if (x >= 0+t && x < l - t)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
		t++;
	}
	return 0;
}
