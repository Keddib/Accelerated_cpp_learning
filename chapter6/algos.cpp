#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <ostream>

using namespace std;


bool is_neg(int num)
{
	return num < 0;
}

bool not_neg(int num)
{
	return !is_neg(num);
}



vector<int> rextract_fails(vector<int>& nums)
{
	vector<int> fail;
	remove_copy_if(nums.begin(), nums.end(), back_inserter(fail), is_neg);
	nums.erase(remove_if(nums.begin(), nums.end(), is_neg), nums.end());
	return fail;
}

vector<int> pextract_fails(vector<int>& nums)
{

	cout << "origin" << endl;
	copy(nums.begin(), nums.end() , ostream_iterator<int>(cout, " "));
	cout << endl;

	vector<int>::iterator iter =
	stable_partition(nums.begin(), nums.end(), not_neg);

	cout << "partition" << endl;
	copy(nums.begin(), nums.end() , ostream_iterator<int>(cout, " "));
	cout << endl;
	vector<int> fail(iter, nums.end());

	cout << "constrtor new fails" << endl;
	copy(fail.begin(), fail.end() , ostream_iterator<int>(cout, " "));
	cout << endl;
	nums.erase(iter, nums.end());

	cout << "ears from nums" << endl;
	copy(nums.begin(), nums.end() , ostream_iterator<int>(cout, " "));
	cout << endl;
	return fail;
}





int main()
{
	int num;
	 vector<int> nums;
	 while (cin >> num)
	 	nums.push_back(num);
	pextract_fails(nums);

	// vector<int>::iterator end;
	// // num = accumulate(nums.begin(), nums.end(), 20);
	// copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));

	// cout << endl;

	// end = remove_if(nums.begin(), nums.end(), is_neg);
	// // cout << num << endl;

	// copy(nums.begin(), end , ostream_iterator<int>(cout, " "));

	return 0;
}
