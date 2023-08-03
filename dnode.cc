/**
 *	 @file: dnode.cc
 * @author: Riley Reedy
 *	 @date: 7/27/23
 *	@brief: Class DNode implementation that is used in a singular linked list.
 */

#include "dnode.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename DataType>
DNode<DataType>::DNode(const DataType newData, DNode<DataType> *newNext,
							 DNode<DataType> *newPrevious)
{
	data = newData;
	next = newNext;
	previous = newPrevious;
}

template <typename DataType>
void					DNode<DataType>::setData(const DataType &newData)
{
	data = newData;
}

template <typename DataType>
void					DNode<DataType>::setNext(DNode<DataType> *newNext)
{
	next = newNext;
}

template <typename DataType>
void					DNode<DataType>::setPrevious(DNode<DataType> *newPrevious)
{
	previous = newPrevious;
}

// getters
template <typename DataType>
DataType				DNode<DataType>::getData() const
{
	return (data);
}

template <typename DataType>
const DNode<DataType>	*DNode<DataType>::getNext() const
{
	return (next);
}

template <typename DataType>
DNode<DataType>			*DNode<DataType>::getNext()
{
	return (next);
}

template <typename DataType>
const DNode<DataType>	*DNode<DataType>::getPrevious() const
{
	return (previous);
}

template <typename DataType>
DNode<DataType>			*DNode<DataType>::getPrevious()
{
	return (previous);
}
