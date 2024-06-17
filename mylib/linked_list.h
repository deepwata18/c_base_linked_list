#pragma once

#include <iostream>

#include "node.h"

namespace mylib
{
	template <typename T>
	class linked_list
	{
		class iterator
		{
		public:
			iterator(node<T>* n = nullptr)
			{
				_ptr = n;
			}

			iterator& operator ++() // 전위 증가 연산자
			{
				_ptr = _ptr->next;
				return *this;
			}
			iterator operator ++(int) // 후위 증가 연산자
			{
				iterator ret_it(_ptr);
				operator++();
				return ret_it;
			}
			iterator& operator --() // 전위 증가 연산자
			{
				_ptr->prev;
				return *this;
			}
			iterator operator --(int) // 후위 증가 연산자
			{
				iterator ret_it(_ptr);
				operator--();
				return ret_it;
			}

			T& operator *() // 현재 node의 데이터를 반환
			{
				return _ptr->data;
			}

			bool operator == (const iterator& other)
			{
				return other._ptr == this->_ptr;
			}
			bool operator != (const iterator& other)
			{
				return other._ptr != this->_ptr;
			}

		private:
			node<T>* _ptr;

			friend class linked_list;
		};

	public:
		linked_list()
		{
			_size = 0;

			_head.data = NULL;
			_head.next = &_tail;
			_head.prev = nullptr;

			_tail.data = NULL;
			_tail.next = nullptr;
			_tail.prev = &_head;
		}
		~linked_list() { }

		void push_front(T data);
		void push_back(T data);

		void pop_front();
		void pop_back();

		void clear();

		int size();

		bool empty();

		iterator erase(iterator iter);
		void remove(T data);

		iterator begin();
		iterator end();

	private:
		int _size;

		node _head;
		node _tail;
	};

	template<typename T>
	inline void linked_list<T>::push_front(T data)
	{
		node<T>* n = new node<T>{ data, &_head, _head.next };
		_head.next->prev = n;
		_head.next = n;

		_size++;
	}
	template<typename T>
	inline void linked_list<T>::push_back(T data)
	{
		node<T>* n = new node<T>{ data, _tail.prev, &_tail };
		_tail.prev->next = n;
		_tail.prev = n;

		_size++;
	}

	template<typename T>
	inline void linked_list<T>::pop_front()
	{
		_head.next = _head.next->next;

		_size--;
	}
	template<typename T>
	inline void linked_list<T>::pop_back()
	{
		_tail.prev = _tail.prev->prev;

		_size--;
	}

	template<typename T>
	inline void linked_list<T>::clear()
	{
		_size = 0;

		_head.next = &_tail;
		_tail.prev = &_head;
	}

	template<typename T>
	inline int linked_list<T>::size()
	{
		return _size;
	}

	template<typename T>
	inline bool linked_list<T>::empty()
	{
		return _size == 0 && 
			_head.next == &_tail && _tail.prev == &_head; // For Debug (Head와 Tail이 비어있는 경우 서로를 가리키는지 확인)
	}

	template<typename T>
	inline linked_list<T>::iterator linked_list<T>::erase(iterator iter)
	{
		node<T>* cur = iter._ptr;
		cur->prev = cur->next;
		cur->next->prev = cur->prev;
		iterator ret(cur->next);
		delete cur;
		return ret;
	}
	template<typename T>
	inline void linked_list<T>::remove(T data)
	{
		iterator iter = begin();
		while (iter != end())
		{
			if (*iter == Data)
			{
				erase(iter);
			}

			++iter;
		}
	}

	template<typename T>
	inline linked_list<T>::iterator linked_list<T>::begin()
	{
		iterator ret(_head->next);
		return ret;
	}
	template<typename T>
	inline linked_list<T>::iterator linked_list<T>::end()
	{
		iterator ret(_tail->prev);
		return ret;
	}
}

