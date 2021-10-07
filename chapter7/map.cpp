/// map example



#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>



//split
using namespace std;

bool	not_space(char c)
{
	return !isspace(c);
}

bool	space(char c)
{
	return isspace(c);
}

vector<string> ft_split(const string &s)
{
	vector<string> strs;
	typedef string::const_iterator iter;

	iter i = s.begin();
	while (i != s.end())
	{
		i = find_if(i, s.end(), not_space);

		iter j = find_if(i, s.end(), space);

		if (i != s.end())
			strs.push_back(string(i, j));
		i = j;
	}
	return strs;
}


//find all the lines that refer to each word int the input

std::map<std::string, std::vector<int> >
	xref(std::istream &in,
		std::vector<std::string> find_words(const std::string &) = ft_split)
{
	std::string line;
	int line_number = 0;
	std::map<std::string, std::vector<int> > ret;

	//read the next line
	while (getline(in, line))
	{
		++line_number;
		std::vector<std::string> words = find_words(line);
// remember that each word occurs on the current line
        for (std::vector<std::string>::const_iterator it = words.begin();
             it != words.end(); ++it)
		{
            ret[*it].push_back(line_number);
		}
	}
	return ret;
}


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;
    // read the input
    while (getline(in, line)) {
        // split the input into words
        vector<string> entry = ft_split(line);
        if (!entry.empty())
            // use the category to store the associated rule
            ret[entry[0]].push_back(
                Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

bool bracketed(const string& s)
{
return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void	gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        // from which we select one at random
        const Rule& r = c[nrand(c.size())];
        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}



int main()
{
	// call  xref using  split by default
	map<string, vector<int> > ret = xref(cin);
	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		 it != ret.end(); ++it) {
		// write the word
		cout << it->first << " occurs on line(s): ";
		// followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;       //  write the first line number
		++line_it;
		// write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		// write a new line to separate each word from the next
		cout << endl;
	}
	return 0;
}
