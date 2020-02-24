#ifndef SET_SET_H
#define SET_SET_H


#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>


#include "Exceptions.h"
#include "FunctionalClasses.h"
#include "ComparisonElem.h"


using namespace std;


template<typename T>
class Set
{
public:
    Set();
    Set(unsigned _capacity);
    Set(const Set<T> &anotherSet);
    Set(const Set<T> &&anotherSet);
    ~Set();
    void addElement(T elem);
    void pop(T elem);
    unsigned capacity();
    unsigned size();
    void popPred(bool predicate (T));
    int find(T elem);
    template <typename M>
    int findPred(M elem); 
    template <typename M, typename S>
    int findPred(M elem, S asd);
    Set<T>& operator = (Set<T> &anotherSet);
    Set<T>& operator = (Set<T>&& right);
    Set<T>  operator + (Set<T> &anotherSet);
    Set<T>  operator * (Set<T> &anotherSet);
    Set<T>  operator - (Set<T> &anotherSet);
    T operator [] (unsigned index);
private:
    T *_data;
    size_t _capacity;
    size_t _size;
};
template<typename T>
Set<T>::Set() : _capacity(0),
                _size(0)
{
    _data = new T [_size];
};

template<typename T>
Set<T>::Set(unsigned capacity) : _size(0)
{
    _capacity = capacity;
    _data = new T [_capacity];
};

template<typename T>
Set<T>::Set(const Set<T>& anotherSet)
{
    _size = anotherSet._size;
    _capacity = anotherSet._capacity;
    if(anotherSet._data && anotherSet._size)
    {
		this->_data = new T[_size];
		for (int i = 0; i < _size; ++i)
        {
            (this->_data[i]) = anotherSet._data[i];
        }	
	}
	else
	{
		this->_data = nullptr;
		_size = 0;
	}
};

template<typename T>
Set<T>::Set(const Set<T> &&anotherSet)
{
    _capacity = anotherSet._capacity;
    _size = anotherSet._size;
    _data = new T[_size];
    for (int i = 0; i < _size; ++i)
    {
        _data[i] = anotherSet._data[i];
    }
};
                                     
template<typename T>
Set<T>::~Set()
{
    if (_data != nullptr)
    {
        delete[] _data;
    }
};

template<typename T>
void Set<T>::addElement(T elem)
{
    if(_size == _capacity)
    {
        throw ErrorParam();
    }
    else
    {
        _data[_size++] = T (elem);
    }
};

template<typename T>
unsigned Set<T>::capacity()
{
    return _capacity;
};

template <typename T>
unsigned Set<T>::size()
{
    return _size;
};

template<typename T>
void Set<T>::pop(T elem)
{
    int index = 0;
    for(int i = 0; i < _size; ++i)
    {
        if (_data[i] == elem)
        {
            index = i;
        }
    }
    for (int i = index; i < _size - 1; ++i)
    {
        _data[i] = _data[i+1]; 
    }
    --_size; 
};

template<typename T>
void Set<T>::popPred(bool predicate (T))
{
    for(int i = 0; i < _size; ++i)
    {
        if(predicate(_data[i]) == true)
        {
            pop(_data[i]);
            --i;
        }
    }
};

template <typename T>
int Set<T>::find(T elem)
{
    for(int i = 0; i < _size; ++i)
    {
        if(isEqual(_data[i], elem)) 
        {
            return i;
        }
    }
    return -1;
};

template <typename T>
template <typename M>
int Set<T>::findPred(M elem)
{
    for (size_t i = 0; i < _size; ++i)
    {
        if(elem(_data[i]))
        {
            return i;
        }
    }
    return -1;
};

template <typename T>
template <typename M, typename S>
int Set<T>::findPred(M elem, S asd)
{
    for (size_t i = 0; i < _size; ++i)
    {
        if(elem(_data[i], asd))
        {
            return i;
        }
    }
    return -1;
};

template <typename T>
Set<T>& Set<T>::operator=(Set<T> &anotherSet)
{
    
    if(&anotherSet == this)
    {
        return *this;
    }
    if(anotherSet.size() >_capacity)
    {
        throw ErrorParam();
    }
    for(int i = 0; i < (_size = anotherSet.size()); ++i)
    {
        _data[i] = anotherSet._data[i];
    }
    return *this;
};

template <typename T>
Set<T>& Set<T>::operator=(Set<T> &&anotherSet)
{
    
    if(&anotherSet == this)
    {
        return *this;
    }
    if (anotherSet.capacity() > _capacity)
    {
        throw ErrorParam();
    }
    this->_data = anotherSet._data;
    this->_size = anotherSet._size;
    this->_capacity =anotherSet._capacity;

    return *this;
};

template<typename T>
Set<T> Set<T>::operator+(Set<T> &anotherSet)
{
    Set<T> set(_capacity + anotherSet.capacity());
    int counter = 0;

    for(int i = 0; i < _size; ++i)
    {
        set.addElement(_data[i]);

    }
    for(int i = 0; i < anotherSet.size(); ++i)
    {
        for(int j = 0; j < _size; ++j)
        {
            if(_data[j] != anotherSet._data[i])
            { 
                ++counter;
            }
        } 
        if (counter == _size)
        {
            set.addElement(anotherSet._data[i]);
        }   
        counter = 0;
    }

    return set;
};
template<typename T>
Set<T> Set<T>::operator*(Set<T> &anotherSet)
{
     Set<T> set(_capacity);
     for(int i = 0; i < _size; ++i)
     {
         for(int j = 0; j < anotherSet.size(); ++j)
         {
             if(isEqual(_data[i], anotherSet._data[j]))
             {
                set.addElement(_data[j]);
             }
         }
     } 
    return set;
};

template<typename T>
Set<T> Set<T>::operator-(Set<T> &anotherSet)
{
     Set <T> set(_size);
     for(int i = 0; i < _size; ++i)
     {
         for(int j = 0; j < anotherSet.size(); ++j)
         {
             if(isEqual(_data[i], anotherSet._data[j]))
             {
                 pop(_data[i]);
             }
         }
     }
     for(int i = 0; i < _size; ++i)
     {
         set.addElement(_data[i]);
     }
     return set;
};

template <typename T>
T Set<T>::operator[](unsigned index)
{
    if(index >=_size)
    {
        throw ErrorParam();
    }
    else
    {
        return _data[index];
    }
};


#endif //SET_SET_H
