#ifndef LET10STACK_COPY_H
#define LET10STACK_COPY_H


class NoCopy
{
private:
    NoCopy(const NoCopy&){}
    void operator=(const NoCopy&){} 
};


#endif //LET10STACK_COPY_H
