#ifndef LET10STACK_EXCEPTION_H
#define LET10STACK_EXCEPTION_H


#include<stdexcept>


class StackOverflow
: public std::exception
{

};
class StackIsEmpty
: public std::exception
{

};


#endif //LET10STACK_EXCEPTION_H
