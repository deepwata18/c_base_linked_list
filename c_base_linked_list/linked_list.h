#pragma once

#include "node.h"

namespace mylib
{
	template <typename T>
	class linked_list
	{
		class iterator
		{
		public:
			iterator(node* n = nullptr)
			{

			}

			iterator operator ++(int) // 후위 증가 연산자
			{

			}
			iterator& operator ++() // 전위 증가 연산자
			{
				return &this;
			}
			iterator operator --(int) // 후위 증가 연산자
			{

			}
			iterator& operator --() // 전위 증가 연산자
			{
				return &this;
			}

			T& operator *() // 현재 node의 데이터를 반환
			{

			}

			bool operator == (const iterator& other)
			{

			}
			bool operator != (const iterator& other)
			{

			}

		private:
			node* _n;
		};

	public:
		linked_list();
		~linked_list();

		void push_front(T data);
		void push_back(T data);

		void pop_front();
		void pop_back();

		void clear();

		int length();

		bool isEmpty();

		iterator erase(iterator iter);
		void remove(T data);

		iterator begin();
		iterator end();

	private:
		int _len;

		node _head;
		node _tail;
	};

	template<typename T>
	inline linked_list<T>::linked_list()
	{
	}
	template<typename T>
	inline linked_list<T>::~linked_list()
	{
	}

	template<typename T>
	inline void linked_list<T>::push_front(T data)
	{
	}
	template<typename T>
	inline void linked_list<T>::push_back(T data)
	{
	}

	template<typename T>
	inline void linked_list<T>::pop_front()
	{
	}
	template<typename T>
	inline void linked_list<T>::pop_back()
	{
	}

	template<typename T>
	inline void linked_list<T>::clear()
	{
	}

	template<typename T>
	inline int linked_list<T>::length()
	{
		return 0;
	}

	template<typename T>
	inline bool linked_list<T>::isEmpty()
	{
		return false;
	}

	template<typename T>
	inline linked_list<T>::iterator linked_list<T>::erase(linked_list<T>::iterator iter)
	{
		return NULL;
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
		return iterator();
	}
	template<typename T>
	inline linked_list<T>::iterator linked_list<T>::end()
	{
		return iterator();
	}
}

