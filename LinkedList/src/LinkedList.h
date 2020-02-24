#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include <algorithm>
#include <iostream>
#include <iterator>


using namespace std;


template <typename T>
class LinkedList
{
	class ListNode
	{
	public:
		ListNode()
		{
			_prev = this;
			_next = this;
			_value = T();
		}
		ListNode(ListNode* prev, ListNode* next, T value)
		{
			_prev = prev;
			_next = next;
			_value = value;
			_prev->_next = this;
			_next->_prev = this;
		}
		ListNode* _prev;
		ListNode* _next;
		T _value;
	};

public:


	class iterator : public std::iterator<bidirectional_iterator_tag, T>
	{
	public:
		iterator(ListNode* node);

		inline iterator& operator++();
		inline iterator operator++(int unused);
		inline iterator& operator--();
		inline iterator operator--(int unused);

		inline T& operator*();
		inline T* operator->();

		inline bool operator==(const iterator& other);
		inline bool operator!=(const iterator& other);

		friend class LinkedList;
	private:
		ListNode* _node;
	};


	class const_iterator : public std::iterator<bidirectional_iterator_tag, T>
	{
	public:
		const_iterator(ListNode* node);

		inline const_iterator& operator++();
		inline const_iterator operator++(int unused);
		inline const_iterator& operator--();
		inline const_iterator operator--(int unused);

		inline const T& operator*();
		inline const T* operator->();

		inline bool operator==(const const_iterator& other);
		inline bool operator!=(const const_iterator& other);

		friend class LinkedList;
	private:
		ListNode* _node;
	};


	class reverse_iterator : public std::iterator<bidirectional_iterator_tag, T>
	{
	public:
		reverse_iterator(ListNode* node);

		inline reverse_iterator& operator++();
		inline reverse_iterator operator++(int unused);
		inline reverse_iterator& operator--();
		inline reverse_iterator operator--(int unused);
		inline T& operator*();
		inline T* operator->();

		inline bool operator==(const reverse_iterator& other);
		inline bool operator!=(const reverse_iterator& other);

		friend class LinkedList;
	private:
		ListNode* _node;
	};


	class const_reverse_iterator : public std::iterator<bidirectional_iterator_tag, T>
	{
	public:
		const_reverse_iterator(ListNode* node);

		inline const_reverse_iterator& operator++();
		inline const_reverse_iterator operator++(int unused);
		inline const_reverse_iterator& operator--();
		inline const_reverse_iterator operator--(int unused);

		inline const T& operator*();
		inline const T* operator->();

		inline bool operator==(const const_reverse_iterator& other);
		inline bool operator!=(const const_reverse_iterator& other);

		friend class LinkedList;
	private:
		ListNode* _node;
	};


	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& copyList);
	LinkedList(LinkedList&& importList);
	LinkedList& operator=(const LinkedList& copyList);
	LinkedList& operator=(LinkedList&& importList);

	bool empty() const;

	iterator insert(iterator where, T value);
	void push_back(T value);
	void push_front(T value);

	iterator erase(iterator where);
	void remove(const T& value);

	void reverse();

	iterator begin();
	const_iterator begin() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

private:
	ListNode* _head;
	
};

template <typename T>
LinkedList<T>::iterator::iterator (ListNode* node)
{
	_node = node;
};

template <typename T>
inline typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator++()
{
	_node = _node -> _next;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++(int unused)
{
	auto old = *this;
	_node = _node -> _next;
	return old;
};

template <typename T>
inline typename LinkedList<T>::iterator& LinkedList<T>::iterator::operator--()
{
	_node = _node -> _prev;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::iterator LinkedList<T>::iterator::operator--(int unused)
{
	auto old = *this;
	_node = _node -> _prev;
	return old;
};

template <typename T>
inline T& LinkedList<T>::iterator::operator*()
{
	return _node -> _value;
};

template <typename T>
inline T* LinkedList<T>::iterator::operator->()
{
	return &_node -> _value;
};

template <typename T>
inline bool LinkedList<T>::iterator::operator==(const iterator& other)
{
	return _node == other._node;
};

template <typename T>
inline bool LinkedList<T>::iterator::operator!=(const iterator& other)
{
	return _node != other._node;
};


//методы класса const_iterator
template <typename T>
LinkedList<T>::const_iterator::const_iterator(ListNode* node)
{
	_node = node;
};

template <typename T>
inline typename LinkedList<T>::const_iterator& LinkedList<T>::const_iterator::operator++()
{
	_node = _node->_next;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::const_iterator LinkedList<T>::const_iterator::operator++(int unused)
{
	auto old = *this;
	_node = _node->_next;
	return old;
};

template <typename T>
inline typename LinkedList<T>::const_iterator& LinkedList<T>::const_iterator::operator--()
{
	_node = _node->_prev;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::const_iterator LinkedList<T>::const_iterator::operator--(int unused)
{
	auto old = *this;
	_node = _node->_prev;
	return old;
};

template <typename T>
inline const T& LinkedList<T>::const_iterator::operator*()
{
	return _node->_value;
};

template <typename T>
inline const T* LinkedList<T>::const_iterator::operator->() 
{
	return &_node->_value;
};

template <typename T>
inline bool LinkedList<T>::const_iterator::operator==(const const_iterator& other)
{
	return _node == other._node;
};

template <typename T>
inline bool LinkedList<T>::const_iterator::operator!=(const const_iterator& other)
{
	return _node != other._node;
};


//методы класса reverse_iterator
template <typename T>
LinkedList<T>::reverse_iterator::reverse_iterator(ListNode* node)
{
	_node = node;
};

template <typename T>
inline typename LinkedList<T>::reverse_iterator& LinkedList<T>::reverse_iterator::operator++()
{
	_node = _node->_prev;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::reverse_iterator LinkedList<T>::reverse_iterator::operator++(int unused)
{
	auto old = *this;
	_node = _node->_prev;
	return old;
};

template <typename T>
inline typename LinkedList<T>::reverse_iterator& LinkedList<T>::reverse_iterator::operator--()
{
	_node = _node->_next;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::reverse_iterator LinkedList<T>::reverse_iterator::operator--(int unused)
{
	auto old = *this;
	_node = _node->_next;
	return old;
};

template <typename T>
inline T& LinkedList<T>::reverse_iterator::operator*()
{
	return _node->_value;
};

template <typename T>
inline T* LinkedList<T>::reverse_iterator::operator->()
{
	return &_node->_value;
};

template <typename T>
inline bool LinkedList<T>::reverse_iterator::operator==(const reverse_iterator& other)
{
	return _node == other._node;
};

template <typename T>
inline bool LinkedList<T>::reverse_iterator::operator!=(const reverse_iterator& other)
{
	return _node != other._node;
};


//методы класса const_reverse_iterator
template <typename T>
LinkedList<T>::const_reverse_iterator::const_reverse_iterator(ListNode* node)
{
	_node = node;
};

template <typename T>
inline typename LinkedList<T>::const_reverse_iterator& LinkedList<T>::const_reverse_iterator:: operator++()
{
	_node = _node->_prev;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::const_reverse_iterator LinkedList<T>::const_reverse_iterator::operator++(int unused)
{
	auto old = *this;
	_node = _node->_prev;
	return old;
};

template <typename T>
inline typename LinkedList<T>::const_reverse_iterator& LinkedList<T>::const_reverse_iterator::operator--()
{
	_node = _node->_next;
	return *this;
};

template <typename T>
inline typename LinkedList<T>::const_reverse_iterator LinkedList<T>::const_reverse_iterator::operator--(int unused)
{
	auto old = *this;
	_node = _node->_next;
	return old;
};

template <typename T>
inline const T& LinkedList<T>::const_reverse_iterator::operator*()
{
	return _node->_value;
};

template <typename T>
inline const T* LinkedList<T>::const_reverse_iterator::operator->()
{
	return &_node->_value;
};

template <typename T>
inline bool LinkedList<T>::const_reverse_iterator::operator==(const const_reverse_iterator& other)
{
	return _node == other._node;
};

template <typename T>
inline bool LinkedList<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) 
{
	return _node != other._node;
};


//Методы класса LinkedList
template <typename T>
LinkedList<T>::LinkedList() 
{
	_head = new ListNode();
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	if (!(_head == nullptr))
	{
		for (auto i = begin(); i != end(); ++i)
		{
			erase(i);
		}
	}
};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& copyList) : LinkedList()
{
	ListNode* _current = copyList._head->_next;
	while (_current != copyList._head)
	{
		push_back(_current->_value);
		_current = _current->_next;
	}
};

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& importList)
{
	_head = importList._head;
	importList._head = nullptr;
};

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& copyList)
{
	if (this == &copyList)
	{
		return *this;
	}
	else
	{
		for (auto i = begin(); i != end(); ++i)
		{
			erase(i);
		}
		_head = new ListNode();
		ListNode* _current = copyList._head->_next;
		while (_current != copyList._head)
		{
			push_back(_current->_value);
			_current = _current->_next;
		}
		return *this;
	}
};

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& importList)
{
	if (this == &importList)
	{
		return *this;
	}
	else
	{
		for (auto i = begin(); i != end(); ++i)
		{
			erase(i);
		}
		_head = importList._head;
		importList._head = nullptr;
	}
	return *this;
};

template <typename T>
bool LinkedList<T>::empty() const
{
	if (_head->_next == _head)
	{
		return true;
	}
	else
	{
		return false;
	}
};

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator where, T value)
{
	return iterator(new ListNode(where._node->_prev, where._node, value));
};

template <typename T>
void LinkedList<T>::push_back(T value)
{
	insert(iterator(_head), value);
};

template <typename T>
void LinkedList<T>::push_front(T value)
{
	insert(iterator(_head->_next), value);
};

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(iterator where)
{
	auto nextWhere = ++where;
	--where;
	nextWhere._node->_prev = where._node->_prev;
	auto previousWhere = --where;
	++where;
	previousWhere._node->_next = where._node->_next;
	where._node = nextWhere._node;

	return where;
};

template <typename T>
void LinkedList<T>::remove(const T& value)
{
	for (auto i = begin(); i != end(); ++i)
	{
		if (value == *i)
		{
			erase(i);
			break;
		}
	}
};

template <typename T>
void LinkedList<T>::reverse()
{
	ListNode* _current = _head;
	do 
	{
		swap(_head->_next, _head->_prev);
		_current = _current->_next;
	} while(_current !=_head);	
};

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
	return iterator(_head->_next);
};

template <typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::begin() const
{
	return const_iterator(_head->_next);
};

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin()
{
	return reverse_iterator(_head->_prev);
};

template <typename T>
typename LinkedList<T>::const_reverse_iterator LinkedList<T>::rbegin() const
{
	return const_reverse_iterator(_head->_prev);
};

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
	return iterator(_head);
};

template <typename T>
typename LinkedList<T>::const_iterator LinkedList<T>::end() const
{
	return const_iterator(_head);
};

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend()
{
	return reverse_iterator(_head);
};

template <typename T>
typename LinkedList<T>::const_reverse_iterator LinkedList<T>::rend() const
{
	return const_reverse_iterator(_head);
};


#endif //LINKEDLIST_LINKEDLIST_H
