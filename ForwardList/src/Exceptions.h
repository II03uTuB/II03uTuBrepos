#ifndef FORWARDLIST_EXCEPTIONS_H
#define FORWARDLIST_EXCEPTIONS_H


#include <stdexcept>


class ListIsEmpty : public std::exception {};

class OutOfRange : public std::exception {};

#endif //FORWARDLIST_EXCEPTIONS_H
