#ifndef LET10STACK_COPY_H
#define LET10STACK_COPY_H

// это хорошо
class NoCopy
{
private:
    NoCopy(const NoCopy&){}
    // только вот это тогда не надо, ибо у вас запрет оператора присваивания будет в классе Assignment
    void operator=(const NoCopy&){} 
};


#endif //LET10STACK_COPY_H
