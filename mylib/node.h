#pragma once

namespace mylib
{
	template <typename T>
	class node
	{
	public:
		T data;

		node* prev; // 앞쪽 node (front)
		node* next; // 뒤쪽 node (back)
	};
}