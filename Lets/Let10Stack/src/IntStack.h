#ifndef LET10STACK_INTSTACK_H
#define LET10STACK_INTSTACK_H


#include "Exception.h"
#include "Assignment.h"
#include "Copy.h"

class IntStack
{
public:
    IntStack(unsigned int _maxElementOfArray);
    ~IntStack();
    void push(int elem);
    int top();
    void pop();
    int capacity()const;
    bool empty();
    int  size() const;
    
private:
	int* _array;
    unsigned int _sizeOfArray;
	int _currentElementOfArray;	
};
#endif // !LET10STACK_INTSTACK_H
