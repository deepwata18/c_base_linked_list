#pragma once

namespace mylib
{
	template <typename T>
	struct node
	{
		T data;

		node* prev; // ���� node (front)
		node* next; // ���� node (back)
	};
}