#include"IntStack.h"

// что-то все тела уехали на 1 таб вправо

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
    // отступы
    _array[--_currentElementOfArray];

}
int IntStack::capacity() const
	{
		return _sizeOfArray;
	}
bool IntStack::empty()
	{
    // если у вас условная конструкция и там всего лишь return, то пишите в одну строку:
    return _currentElementOfArray == 0;
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
