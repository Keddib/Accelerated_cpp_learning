#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <cctype>

using namespace std;

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

string::iterator
url_beg(string::iterator &b, string::iterator &e)
{
	return b;
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";
	typedef string::const_iterator iter;

	// i marks where the separator was found
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		// make sure the separator isn't at the beginning or end of the line
		if (i != b && i + sep.size() != e)
		{
			// beg marks the beginning of the protocol-name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;
				// is there at least one appropriate character before and after the separator?
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		// the separator we found wasn't part of a URL advance i past this separator
		i += sep.size();
	}
	return e;
}


vector<string>	find_urls(const string &s)
{
	vector<string> vec;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	while (b != e)
	{
		// find beginning of url
		b = url_beg(b, e);
		//find ending of url
		if (b != e)
		{
			iter after = url_end(b, e);
			vec.push_back(string(b, after));
			b = after;
		}
	}
	return vec;
}

int main()
{
	string s = "   ://  hello://test  http://google.com https://me.me jsgfh  smd slkdj sdljsd jsd slkdj ";
	vector<string> vec = find_urls(s);
	copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}
