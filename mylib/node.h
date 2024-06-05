#pragma once

namespace mylib
{
	template <typename T>
	struct node
	{
		T data;

		node* prev; // 앞쪽 node (front)
		node* next; // 뒤쪽 node (back)
	};
}