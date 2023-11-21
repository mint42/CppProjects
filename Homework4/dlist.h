/**
 *   @file: dlist.h
 * @author: Riley Reedy
 *   @date: 8/03/23
 *  @brief: Class List uses the DNode class to create a singular
 *          linked list. It also includes an interator class.
 */

#ifndef LIST_H
# define LIST_H

# include "dnode.h"
# include <iostream>

using namespace std;

template <typename DataType>
class		DList
{
	public:

		template <typename ItDataType>
		class	Iterator
		{
			public:
				using iterator_category = bidirectional_iterator_tag;
				using diference_type = ptrdiff_t;
        		using value_type = DNode<ItDataType>;
        		using pointer = DNode<ItDataType> *;
        		using reference = DNode<ItDataType> &;

				/*
				 *	Function:			Constructor
				 *	@param(initial):	iterator pointer to be set to current
				 *	@return:			N/A
				 */
				Iterator(DNode<ItDataType> *initial = nullptr) { current = initial; }
				
				/*
				 *	Operator:	*
				 *	@param():	N/A
				 *	@return:	data inside the current iterator
				 */
				ItDataType operator*() const { return (current->getData()); }
				/*
				 *	Operator:	->
				 *	@param():	N/A
				 *	@return:	the current iterator
				 */
				DNode<ItDataType> *operator->() { return (current); }
				/*
				 *	Operator:	++it
				 *	@param():	N/A
				 *	@return:	iterator after increment
				 */
				Iterator &operator++()
				{
					current = current->getNext();
					return *this;
				}
				/*
				 *	Operator:	it++
				 *	@param():	N/A
				 *	@return:	iterator before increment
				 */
				Iterator operator++(int)
				{
					Iterator original = *this;
					current = current->getNext();
					return original;
				}
				/*
				 *	Operator:	--it
				 *	@param():	N/A
				 *	@return:	iterator after decrement
				 */
				Iterator &operator--()
				{
					current = current->getPrevious();
					return *this;
				}
				/*
				 *	Operator:	--it--
				 *	@param():	N/A
				 *	@return:	iterator before decrement
				 */
				Iterator operator--(int)
				{
					Iterator original = *this;
					current = current->getPrevious();
					return original;
				}
				/*
				 *	Operator:		==
				 *	@param(other):	iterator to compare to current
				 *	@return:		true if they're equal, else false
				 */
				bool operator==(const Iterator other) const
				{
					return current == other.current;
				}
				/*
				 *	Operator:		!=
				 *	@param(other):	iterator to compare to current
				 *	@return:		false if they're equal, else true
				 */
				bool operator!=(const Iterator other) const
				{
					return current != other.current;
				}

			private:
				DNode<ItDataType> *current;
		};

		/**
		 *	Constructor:			include default values for data and next
		 *	@param(newHead):		sets the head of the list to the given
		 *							node or nullptr
		 *	@param(newTail):		sets the tail of the list to the given
		 *							node or nullptr
		 */
		DList(DNode<DataType> *newHead = nullptr, DNode<DataType> *newTail = nullptr);
		/*
		 *	Default Destructor:		destroys the list
		 *	@param():				N/A
		 */
		~DList();

		using iterator = Iterator<DataType>;
		Iterator<DataType> begin() { return Iterator<DataType>(head); }
		Iterator<DataType> end() { return Iterator<DataType>(tail); }

		// List algorithms
		/*
		 *	Function:	length
		 *				returns the length of the list
		 *	@param():	N/A
		 *	@return:	the length
		 *
		 */
		size_t			length() const;
		/*
		 *	Function:	output
		 *				prints the list items to the commandline
		 *	@param():	N/A
		 *	@return:	N/A
		 *
		 */
		void			output() const;

		/*
		 *	Function:		search
		 *					searches for and returns the node with the data
		 *					matching target
		 *	@param(target):	the target to compare to
		 *	@return:		the node
		 *
		 */
		DNode<DataType>	*search(DataType target);
		/*
		 *	Function:		headInsert
		 *					inserts a new node at the head of the list with
		 *					data equaling value
		 *	@param(value):	the value to add
		 *	@return:		N/A
		 *
		 */
		void			headInsert(DataType value);
		/*
		 *	Function:		insert
		 *					inserts a new node to list with data equaling value
		 *	@param(value):	the value to add
		 *	@return:		N/A
		 *
		 */
		void			insert(DataType value);
		/*
		 *	Function:		insertAfter
		 *					inserts a new node to list with data equaling value
		 *					at the position after the cursor node
		 *	@param(value):	the value to add
		 *	@return:		N/A
		 *
		 */
		void			insertAfter(DNode<DataType> *cursor, DataType value);
		/*
		 *	Function:			deleteNode
		 *						deletes a single node from the list and relinks
		 *	@param(current):	pointer to the current node
		 *	@return:			N/A
		 *
		 */
		void			deleteNode(DNode<DataType> *current);
		/*
		 *	Function:			listHead
		 *						returns the head node
		 *	@param(current):	N/A
		 *	@return:			the head
		 *
		 */
		DNode<DataType>	*listHead();
		/*
		 *	Function:		numOccurrences
		 *					returns the number of times "item" shows up in the list
		 *	@param(item):	item to search for
		 *	@return:		the number of occurances
		 *
		 */
		size_t			numOccurrences(DataType item);
		
	private:
		DNode<DataType>	*head;
		DNode<DataType>	*tail;
};
# include "dlist.cc"
#endif
