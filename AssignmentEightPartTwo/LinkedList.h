#pragma once

#include <iostream>


// Header file for the generic LinkedList class.
template <class T>
class LinkedList
{
private:
	class ListNode
	{
	public:
		T data;
		ListNode* next;
		ListNode* previous;

		ListNode(const T& _data);
		ListNode(const T& _data, ListNode* _next);
		ListNode(const T& _data, ListNode* _next, ListNode* _previous);
	};

	ListNode* head;
	ListNode* tail;
	unsigned int _size;

public:
	LinkedList();
	~LinkedList();

	void append(const T& _data);
	void insert(const T& _data);
	void insert(const T& _data, int index);
	T remove(int index);
	T get(unsigned int index);
	T operator[](unsigned int index);
	int indexOf(const T& _data);
	void display();
	unsigned int size();
	bool isEmpty();
};