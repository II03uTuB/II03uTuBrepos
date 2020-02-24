#ifndef SET_FUNCTIONALCLASSES_H
#define SET_FUNCTIONALCLASSES_H


#include <limits>
#include <iostream>


#include "Thor.h"


using namespace std;


struct AbsSearch 
{
    bool operator() (double &firstElem, double &secondElem)
    {
        return (abs(firstElem - secondElem) < numeric_limits <double>::epsilon());
    }
};
template <typename T>
struct equalVolume
{	
	bool operator()(const Thor &firstElem, const T elem) const
	{	
		return (firstElem.getVolume() == elem);
	}
};

struct notEqualVolume
{	
	bool operator()(const Thor &firstElem, const Thor &secondElem) const
	{	
		return (firstElem.getVolume() != secondElem.getVolume());
	}
};
template <typename L>
struct lessVolume
{
	bool operator()(const Thor &firstElem, const L param) const
	{	
		return (firstElem.getVolume() < param);
	}
};

struct greaterVolume
{	
	bool operator()(const Thor &firstElem, const Thor &secondElem) const
	{	
		return (firstElem.getVolume() > secondElem.getVolume());
	}
}; 


#endif //SET_FUNCTIONALCLASSES_H
