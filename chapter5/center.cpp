#include <vector>
#include <iostream>
#include <string>
#include "my_string.hpp"

using namespace std;

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen  = max(maxlen, v[i].size());
	return maxlen;
}

vector<string> center(const vector<string>& pc)
{
	vector<string> ret;
	vector<string>::const_iterator iter = pc.begin();
	vector<string>::const_iterator end = pc.end();
	string::size_type maxlen = width(pc) + 2;

	while (iter != end)
	{
		string s;
		s = string((maxlen - iter->size()) / 2, ' ') + *iter + string((maxlen - iter->size()) / 2, ' ');
		ret.push_back(s);
		iter++;
	}
	return ret;
}


int main()
{
	// vector<string> v = ft_split("khalid edkdfhdkl fkdjhfdf dk     dkjfh dkjfh dkjfhdkjfhdjkhfdjkhfkdjfh");
	vector<string> v;
	vector<string> tmp = center(v);
	copy(tmp.begin(), tmp.end(), ostream_iterator<string>(cout, "\n"));
}
