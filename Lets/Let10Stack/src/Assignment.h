#ifndef LET10STACK_ASSIGNMENT_H
#define LET10STACK__ASSIGNMENT_H

// это хорошо
class NoAssignment
{
private:
    // А здесь наоборот, не надо объявлять конструктор копирования
    NoAssignment(const NoAssignment&){}
    void operator=(const NoAssignment&){}
};


#endif //LET10STACK_ASSIGNMENT_H
