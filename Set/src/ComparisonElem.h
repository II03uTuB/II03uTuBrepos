#ifndef SET_COMPARISONELEM_H
#define SET_COMPARISONELEM_H


#include <type_traits>
#include <string>


template <class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
isEqual(T& first, T& second) 
{
    return first == second;
};

template <class T>
typename std::enable_if<!std::is_floating_point<T>::value, bool>::type
isEqual(T& first, T& second) 
{
    return fabs(first - second) < std::numeric_limits <double>::epsilon();
};

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
isGreater(T& first, T& second) 
{
    return first > second;
};

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
isLess(T& first, T& second) 
{
    return first < second;
};

template <typename U>
bool GreaterThan(U elem)
{
    if (elem > 50)
    {
        return true;
    }
    else
    {
        return false;
    }
};

template <typename U>
bool LessThan(U elem)
{
    if (elem < 30)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename S>
bool LowerCase(S elem)
{
    if (elem >= 97 && elem <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename S>
bool UpperCase(S elem)
{
    if (elem >= 65 && elem <= 90)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename M>
class findEven
{
public:
    bool operator()(M elem)
    {
        if(elem % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

template <typename Y>
class findNumber
{
public:

    bool operator()(Y elem)
    {
        if(elem >=48 && elem <=57)
        {
            return true;
        }
        else
        {
            return false;
        }  
    }
};


#endif //SET_COMPARISONELEM_H
