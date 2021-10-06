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

void	edit_lv(vector<string> &el, const vector<string> &l, string::size_type &max_s)
{
	typedef vector<string>::size_type v_size;

	v_size lS, rS;
	el.insert(el.end(), l.begin(), l.end());

	lS = el.size();
	rS = l.size();
	while (lS != rS)
	{
		el.push_back(string(max_s, ' '));
		lS = el.size();
	}

}

vector<string> hcat(const vector<string>& l, const vector<string>& r)
{
	vector<string> ret;
	vector<string> editedL;
	string::size_type max_s;
	typedef vector<string>::size_type v_size;

	v_size lS, rS;
	lS = l.size();
	rS = r.size();
	max_s = width(l);
	if (lS < rS)
		edit_lv(editedL, l, max_s);
	else
		editedL = l;
	vector<string>::const_iterator iter = r.begin();
	vector<string>::iterator iter1 = editedL.begin();
	vector<string>::const_iterator end = r.end();
	vector<string>::iterator end1 = editedL.end();
	while (iter1 != end1 && iter != end)
	{
		*iter1 +=*iter;
		++iter;
		++iter1;
	}
	return ret;
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
	// while (getline(cin, s))
	// {
		vector<string> info = ft_split("hello world I am doing well");
		// vector<string> nw = frame(info);
		vector<string> nw = ft_split("done done done");
		vector<string> nw1 = frame(nw);
		// image.insert(image.end(), nw.begin(), nw.end());
		vector<string> image = hcat(nw, nw1);
	// }
		copy(image.begin(), image.end(), ostream_iterator<string>(cout, "\n"));
}
