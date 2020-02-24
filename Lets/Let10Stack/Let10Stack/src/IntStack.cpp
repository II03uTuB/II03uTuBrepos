#include"IntStack.h"


IntStack::IntStack(unsigned int _maxElementOfArray)
		:_sizeOfArray(_maxElementOfArray)
	{
		_currentElementOfArray = 0;
		_array = new int(_maxElementOfArray);
	}
IntStack::~IntStack()
	{
		delete [] _array;
	}
void IntStack::push(int elem)
{
	if(_sizeOfArray ==_currentElementOfArray)
	{
		throw StackOverflow();
	}
	_array[_currentElementOfArray++]=elem;
}
int IntStack::top()
	{
        if(_currentElementOfArray == 0)
        {
            throw StackIsEmpty();
        }
		
		return _array[_currentElementOfArray-1];
	}
void IntStack::pop()
	{
		if (_currentElementOfArray < 0)
        {
            throw StackIsEmpty();
        }
			_array[--_currentElementOfArray];
		
	}
int IntStack::capacity() const
	{
		return _sizeOfArray;
	}
bool IntStack::empty()
	{
		if (_currentElementOfArray == 0)
        {
            return true;
        }
		else return false;
	}
int IntStack::size() const
	{
		return _currentElementOfArray;
	}
