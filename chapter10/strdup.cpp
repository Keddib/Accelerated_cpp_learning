#include <cstring>
#include <algorithm>
#include <iostream>
#include <ostream>

char *strdup(const char *s)
{
	size_t len = strlen(s);
	char *dst(new char[len]);
	std::copy(s, s+len, dst);
	return dst;
}


int main()
{
	char *s = strdup("hello world!");
	std::copy(s, s + strlen(s), std::ostream_iterator<char>(std::cout));
	delete[] s;
	return 0;
}
