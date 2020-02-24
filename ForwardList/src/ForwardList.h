#ifndef FORWARDLIST_FORWARDLIST_H
#define FORWARDLIST_FORWARDLIST_H


#include <iostream>


#include "Exceptions.h"


template<typename T>
class ForwardList
{
public:
	class ListNode
	{
	public:
		ListNode* _next;
		T _value;
		ListNode(ListNode* next, T value) : _value(value), _next(next) {};
	};

	ForwardList();
	ForwardList<T>(const ForwardList& copyObject);
	ForwardList<T>(ForwardList&& importObject);
	void clear() noexcept;
	~ForwardList();

	ListNode* insert_after(ListNode* where, T value);
	auto findIndex(int position);
	void push_back(T value);
	void push_front(T value);
	void remove(T value);

	ListNode* first();
	ListNode* last();
	T get(size_t position);

	bool empty() const noexcept;
	void reverse() noexcept;

	size_t size() const;

	template<typename M>
	friend bool operator==(ForwardList<M>& left, ForwardList<M>& right);

	template<typename U>
	friend bool operator!=(ForwardList<U>& left, ForwardList<U>& right);

private:
	int _size;
	ListNode* _head;
	ListNode* _tail;
};

template <typename T>
ForwardList<T>::ForwardList()
{
	_size = 0;
	_head = nullptr;
	_tail = nullptr;
};

template <typename T>
ForwardList<T>::ForwardList(const ForwardList& copyObject) : ForwardList()
{
	ListNode* _current = copyObject._head;
	while (_current != nullptr)
	{
		push_back(_current->_value);
		_current = _current->_next;
	}
};

template <typename T>
ForwardList<T>::ForwardList(ForwardList&& importObject) : 
_head(importObject._head), _tail(importObject._tail), _size(importObject._size)
{
	importObject._tail = nullptr;
	importObject._head = nullptr;
};

template <typename T>
void ForwardList<T>::clear() noexcept
{
	while (_size)
	{
		ListNode* _current = _head;
		_head = _head->_next;
		delete _current;
		--_size;
	}
};

template <typename T>
ForwardList<T>::~ForwardList()
{
	clear();
};

template<typename T>
typename ForwardList<T>::ListNode* ForwardList<T>::insert_after(ListNode* where, T value)
{
	if (where == nullptr)
	{
		ListNode* tempNode = _head;
		ListNode* newListNode = new ListNode(nullptr, value);
		_head = newListNode;
		if (_tail == nullptr)
		{
			_tail = newListNode;
		}
		_head->_next = tempNode;
		++_size;

		return newListNode;
	}
	else 
	{
		ListNode* newListNode = new ListNode(where->_next, value);
		newListNode->_next = where->_next;
		where->_next = newListNode;
		++_size;

		return newListNode;
	}
};
template<typename T>
auto ForwardList<T>::findIndex(int position) //вспомогательный метод,
											 //необходимый для вставки узла
{
	int number = 1;
	ListNode* _current = _head;
	while (number < position  && _head)
	{
		_current = _current->_next;
		++number;
	}
	return _current;
};

template<typename T>
void ForwardList<T>::remove(T value)
{
	for (size_t i = 1; i < size() + 1; ++i)
	{
		if (get(i) == value)
		{
			ListNode* _current = _head;
			_head = _head->_next;
			--_size;
		}
	}
};

template <typename T>
void ForwardList<T>::push_back(T value)
{
	_tail = insert_after(_tail, value);
};

template<typename T>
void ForwardList<T>::push_front(T value)
{
	_head = insert_after(nullptr, value);
};

template <typename T>
typename ForwardList<T>::ListNode* ForwardList<T>::first()
{
	if (size() == 0)
	{
		throw ListIsEmpty();
	}
	else
	{
		return _head;
	}
};

template <typename T>
typename ForwardList<T>::ListNode* ForwardList<T>::last()
{
	if (size() == 0)
	{
		throw ListIsEmpty();
	}
	else
	{
		return _tail;
	}
};

template <typename T>
T ForwardList<T>::get(size_t position)
{
	int counter = 1;
	ListNode* _current = this->_head;
	if (position <= 0 ||  size() < position)
	{
		throw OutOfRange();
	}
	while (_current != 0)
	{return _current->_value;
		if (counter == position)
		{
			break;
		}
		_current = _current->_next;
		++counter;
	}
	return _current->_value;
};

template <typename T>
bool ForwardList<T>::empty() const noexcept
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};

template <typename T>
void ForwardList<T>::reverse() noexcept
{
	ListNode* _current = _head;
	ListNode* _next = nullptr;
	ListNode* _previous = nullptr;
	_tail = _head;
	while (_current != nullptr)
	{
		_next = _current->_next;
		_current->_next = _previous;
		_previous = _current;
		_current = _next;
	}
	_head = _previous;
};

template <typename T>
size_t ForwardList<T>::size() const
{
	return _size;
};

template<typename M>
bool operator==(ForwardList<M>& left, ForwardList<M>& right) 
{
	if (left._size != right._size)
	{
		return false;
	}
	for (size_t i = 1; i < left.size() +1 ; ++i)
	{
		if (left.get(i) != right.get(i))
		{
			return false;
		}
	}

	return true;
};

template <typename U>
bool operator!=(ForwardList<U> &left, ForwardList<U> &right)
{
	if (left == right)
	{
		return false;
	}
	else
	{
		return true;
	}
};


#endif //FORWARDLIST_FORWARDLIST_H
