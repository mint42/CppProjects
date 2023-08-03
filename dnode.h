/**
 *   @file: dnode.h
 * @author: Riley Reedy
 *   @date: 7/27/23
 *  @brief: Class DNode header file that is used in a doubly linked list.
 */

#ifndef DNODE_H
# define DNODE_H
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

template <typename DataType>
class	DNode
{
	public:
		/**
		 * Constructor: include default values for data and next
		 * @param newData - data being stored, default is the constructor for
		 *                  type, 0 for numbers, false for bool
		 * @param newNext - next pointer within the dnode, default nullptr
		 */
		DNode(const DataType newData = DataType(), DNode *newNext = nullptr,
		      DNode *newPrevious = nullptr);

		// setters
		void		setData(const DataType &newData);
		void		setNext(DNode<DataType> *newNext);
		void		setPrevious(DNode<DataType> *newPrevious);
		
		// getters
		DataType	getData() const;
		const DNode	*getNext() const;
		const DNode	*getPrevious() const;
		DNode		*getNext();
		DNode		*getPrevious();
		
	private:
		DataType	data;
		DNode		*next;
		DNode		*previous;
};

# include "dnode.cc"
#endif
