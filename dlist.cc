/**
 *	 @file: dlist.cc
 * @author: Riley Reedy
 *	 @date: 7/27/23
 *	@brief: Class DList implementation uses the DNode class to create a doubly
 *					linked Dlist.
 */

#include "dlist.h"
#include "dnode.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

template <typename DataType>
DList<DataType>::DList(DNode<DataType> *newHead, DNode<DataType> *newTail)
{
	head = newHead;
	tail = newTail;
}

template <typename DataType>
DList<DataType>::~DList()
{
	// deallocate all the Dnodes
	DNode<DataType> *cursor;
	while (head != nullptr)
	{
		cursor = head;
		head = head->getNext();
		delete cursor;
	}
}

template <typename DataType>
size_t	DList<DataType>::length() const
{
	DNode<DataType> *cursor = head;
	size_t count = 0;
	while (cursor != nullptr)
	{
		count++;
		cursor = cursor->getNext();
	}
	return count;
}

template <typename DataType>
void			DList<DataType>::output() const
{
	DNode<DataType> *cursor = head;
	while (cursor != nullptr)
	{
		cout << cursor->getData() << endl;
		cursor = cursor->getNext();
	}
}

template <typename DataType>
DNode<DataType>	*DList<DataType>::search(DataType target)
{
	DNode<DataType> *cursor = head;
	while (cursor != nullptr)
	{
		if (cursor->getData() == target)
			return cursor;
		cursor = cursor->getNext();
	}
	return nullptr;
}

template <typename DataType>
void			DList<DataType>::headInsert(DataType value)
{
	DNode<DataType> *temp = new DNode<DataType>(value, nullptr, nullptr);

	if (head != nullptr)
	{
		head->setPrevious(temp);
		temp->setNext(head);
	}
	head = temp;
}

template <typename DataType>
void			DList<DataType>::insertAfter(DNode<DataType> *cursor, DataType value)
{
	if (cursor == nullptr)
		return;

	DNode<DataType> *temp;
	temp = new DNode<DataType>;
	temp->setData(value);
	temp->setNext(cursor->getNext());
	temp->setPrevious(cursor);
	if (cursor->getNext() != nullptr) // check if at end of list
		cursor->getNext()->setPrevious(temp);
	cursor->setNext(temp);
}

template <typename DataType>
void				DList<DataType>::deleteNode(DNode<DataType> *cursor)
{
	if (cursor == nullptr) // nothing to delete
		return;
	if (cursor == head)
	{
		head = cursor->getNext();
		if (head != nullptr) // only node?
			head->setPrevious(nullptr);
	}
	else if (cursor->getNext() == nullptr)
	{ // end of list
		// find the previous pointer of  cursor
		DNode<DataType> *previous = cursor->getPrevious();
		previous->setNext(nullptr);
	}
	else
	{
		DNode<DataType> *after = cursor->getNext();
		DNode<DataType> *before = cursor->getPrevious();
		before->setNext(after);
		after->setPrevious(before);
	}
	delete cursor;
}

template <typename DataType>
DNode<DataType>		*DList<DataType>::listHead()
{
	return head;
}

template <typename DataType>
size_t				DList<DataType>::numOccurrences(DataType item)
{
	DNode<DataType> *cursor = head;
	size_t count = 0;

	while (cursor != nullptr)
	{
		if (cursor->getData() == item)
			++count;
		cursor = cursor->getNext();
	}
	return (count);
}
