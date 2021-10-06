#include <string>
#include <vector>
#include <iostream>
#include "my_string.hpp"

using namespace std;



string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen  = max(maxlen, v[i].size());
	return maxlen;
}


vector<string>
hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;
    // continue until we've seen all rows from both pictures
        string s;
    while (i != left.size() || j != right.size()) {
        // construct new string to hold characters from both pictures
        // string s;
        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
        // pad to full width
        s += string(width1 - s.size(), ' ');
        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];
        // add s to the picture we're creating
        ret.push_back(s);
		s.clear();
    }
    return  ret;
}
// string::size_type width(const vector<string>& v)
// {
// 	string::size_type maxlen = 0;
// 	for (vector<string>::size_type i = 0; i != v.size(); ++i)
// 		maxlen  = max(maxlen, v[i].size());
// 	return maxlen;
// }

vector<string> frame(const vector<string>& v)
{
	vector<string> temp;
	vector<string>::size_type max_len = 0;
	vector<string>::const_iterator iter = v.begin();
	vector<string>::const_iterator end = v.end();
	max_len = width(v);
	temp.push_back(string(max_len + 4, '*'));
	iter = v.begin();
	while (iter != end)
	{
		temp.push_back("* " + *iter + string(max_len - (*iter).size(), ' ') + " *");
		iter++;
	}
	temp.push_back(string(max_len + 4, '*'));
	return temp;
}


int main()
{
		vector<string> info = ft_split("hello world I am doing well");
		vector<string> nw = ft_split("done done done Done Done Done Done dlgkhdgkhdkghldghdlkgh");
		string::size_type width1 = width(nw) + 1;
		vector<string> nw1 = frame(nw);
		vector<string> image = hcat(info, nw1);
		copy(image.begin(), image.end(), ostream_iterator<string>(cout, "\n"));
}
