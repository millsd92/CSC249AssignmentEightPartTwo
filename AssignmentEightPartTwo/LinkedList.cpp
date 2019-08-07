#include "LinkedList.h"

// This is a generic doubly linked list class. I decided to use a nested inner class for the list node
// and attempted to keep it as generic as I could implementation-wise.

// Constructor taking only the data. Sets the nodes to nullptr.
template <class T>
LinkedList<T>::ListNode::ListNode(const T& _data)
{
	data = _data;
	next = nullptr;
	previous = nullptr;
}

// Constructor taking the data and a pointer to the next node.
template <class T>
LinkedList<T>::ListNode::ListNode(const T& _data, ListNode* _next)
{
	data = _data;
	next = _next;
	previous = nullptr;
}

// Constructor taking the data and pointers to both the next and previous nodes.
template <class T>
LinkedList<T>::ListNode::ListNode(const T& _data, ListNode* _next, ListNode* _previous)
{
	data = _data;
	next = _next;
	previous = _previous;
}

// Default constructor. The head and tail are initialized to nullptr and the size is initiailized to 0;
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	_size = 0;
}

// Destructor. Deletes every node.
template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode* iterator;
	ListNode* next;

	iterator = head;

	while (iterator != nullptr)
	{
		next = iterator->next;
		delete iterator;
		iterator = next;
	}
}

// Adds an item to the end of the list.
template <class T>
void LinkedList<T>::append(const T& _data)
{
	if (_size > 0)
	{
		tail = tail->next = new ListNode(_data, nullptr, tail);
		_size++;
	}
	else
	{
		head = tail = new ListNode(_data);
		_size++;
	}
}

// Inserts an item at the beginning of the list.
template <class T>
void LinkedList<T>::insert(const T& _data)
{
	if (isEmpty())
	{
		head = tail = new ListNode(_data);
		_size++;
	}
	else
	{
		head = head->previous = new ListNode(_data, head);
		_size++;
	}
}

// Inserts an item at the specified location in the list.
template <class T>
void LinkedList<T>::insert(const T& _data, int index)
{
	if (index < 0 || index > (signed int)_size)
		throw "Invalid index!";
	else if (index < (signed int)_size && index != 0)
	{
		ListNode* iterator = head;
		for (int i = 0; i < index - 1; i++)
			iterator = iterator->next;
		iterator->next = iterator->next->previous = new ListNode(_data, iterator->next, iterator);
		_size++;
	}
	else if (index == (signed int)_size)
		append(_data);
	else
		insert(_data);
}

// Removes the ListNode at an index.
template <class T>
T LinkedList<T>::remove(int index)
{
	if (isEmpty())
		throw "List is empty!";
	else if (index < 0 || index >= (signed int)_size)
		throw "Invalid index!";
	else if (index == 0)
	{
		head = head->next;
		ListNode* returnData = head->previous;
		head->previous = nullptr;
		_size--;
		return returnData->data;
	}
	else if (index == (signed int)_size - 1)
	{
		tail = tail->previous;
		ListNode* returnData = tail->next;
		tail->next = nullptr;
		_size--;
		return returnData->data;
	}
	else
	{
		ListNode* iterator = head;
		for (int i = 0; i < index; i++)
			iterator = iterator->next;
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		_size--;
		return iterator->data;
	}
}

// Returns the data of the item in a given index.
template <class T>
T LinkedList<T>::get(unsigned int index)
{
	if (isEmpty())
		throw "List is empty!";
	else if (index < 0 || index >= (signed int)_size)
		throw "Invalid index!";
	else if (index == 0)
		return head->data;
	else if (index == (signed int)_size - 1)
		return tail->data;
	else
	{
		ListNode* iterator = head;
		for (unsigned int i = 0; i < index; i++)
			iterator = iterator->next;
		return iterator->data;
	}
}

// Operator overload for brackets. Same as calling the get method.
template <class T>
T LinkedList<T>::operator[](unsigned int index) { return get(index); }

// Returns the index of the first item with the given data or -1 if the item isn't found.
template <class T>
int LinkedList<T>::indexOf(const T& _data)
{
	ListNode* iterator = head;
	for (int i = 0; i < (signed int)_size; i++) {
		if (iterator->data == _data)
			return i;
		else
			iterator = iterator->next;
	}
	return -1;
}

// Displays the entire list.
template <class T>
void LinkedList<T>::display()
{
	if (isEmpty())
		throw "List is empty!";
	else
		for (int i = 0; i < (signed int)_size; i++)
			std::cout << get(i) << std::endl;
}

// Simply returns the size of the linked list.
template <class T>
unsigned int LinkedList<T>::size() { return _size; }

// Simply returns a boolean indicating whether the list is empty or not.
template <class T>
bool LinkedList<T>::isEmpty() { return _size == 0; }