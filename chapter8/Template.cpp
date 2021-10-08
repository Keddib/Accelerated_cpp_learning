#include <vector>
#include <iostream>
#include <ostream>


//  template<class T> T median(std::vector<T> v)
//  {
// 	 typdedef typename vector<T>::size_type vec_sz;

// 	 vec_sz size = v.size();
// 	 if (size == 0)
// 	 	throw domain_error("median of an empty vector");

// 	sort(v.begin(), v.end());

// 	vec_sz mid = size / 2;
// 	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
//  }


// Sequential read access
// dst iterators must support all operation supported by  input iterators

template <class  In, class X>
In my_find(In begin, In end, const X& x)
{
	//input iterator
	while (begin != end && *begin != x)
		++begin;
	return begin;
}

// Sequential write access
// dst iterators must support all operation supported by  output iterators

template <class in, class out>
out my_copy(in begin, in end, out dst)
{
	// dst is output iterator.
	while (begin != end)
		*dst++ = *begin++;
	return dst;
}

// Sequential read-write access
// iterators must support all operation supported by an input iterator and output iterator

template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
//	forward iterator beg
    while (beg != end){
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}

// reversible acess

template<class Bi> void reverse(Bi begin, Bi end)
{
	//bidirectional iterators
    while (begin != end) {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

int main()
{
	std::vector<int> nums;

	// for (int i = 0; i < 15; i++)
		// nums.push_back(i);

	// std::cout << "vector src" << std::endl;
	// std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
	// std::cout << std::endl;
	// // std::vector<int>::iterator found;
	// // *found = 15;
	// // found = my_find(nums.begin(), nums.end(), 10);
	// // std::cout << *found << std::endl;
	// std::cout << "vector dis" << std::endl;
	// std::vector<int> tmp(15);
	// my_copy(nums.begin(), nums.end(), tmp.begin());
	// std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<int>(std::cout, " "));
	std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(nums));
	std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout));
	return 0;
}
