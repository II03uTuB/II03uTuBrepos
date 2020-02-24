#ifndef BINARYSEARCH_BINARYSEARCH_H
#define BINARYSEARCH_BINARYSEARCH_H


#include <functional>
#include <vector>


using namespace std;


template <typename IterType, typename T, typename PredType = less<T>>
IterType RecursiveBinarySearch(IterType first, IterType last, T value, PredType pred = PredType()) 
{
	if (first == last)
	{
		return last;
	}

	auto middle = first;
	advance(middle, distance(first, last) / 2);

	if (!pred(*middle, value) && !pred(value, *middle))
	{
		return middle;
	}

	if (pred(*middle, value))
	{
		return RecursiveBinarySearch(++middle, last, value, pred);
	}

	if (pred(value, *middle))
	{
		auto searchResult = RecursiveBinarySearch(first, middle, value, pred);

		return searchResult == middle ? last : searchResult;
	}

	return middle;
}


template <typename IterType, typename T, typename PredType = less<T>>
IterType BinarySearch(IterType first, IterType last, T value, PredType pred = PredType())
{
	auto middle = first;
	while(true)
	{
		advance(middle, distance(first, last) / 2);
        
		if (first == last)
		{
			break;
		}

		if (pred(value, *middle) == true)
		{
			last = middle;
			middle = first;
		}

		if (pred(*middle, value) == true)
		{
			first = ++middle;
		}

		else
		{
			break;
		}
	}

	return middle;
}


#endif //BINARYSEARCH_BINARYSEARCH_H
