#pragma once

namespace mylib
{
	template <typename T>
	class node
	{
	public:
		T data;

		node* prev; // ���� node (front)
		node* next; // ���� node (back)
	};
}