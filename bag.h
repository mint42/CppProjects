/**
 *    @file: bag.h
 *  @author: Riley Reedy
 *    @date: 7/13/23
 *   @brief: Class declaration for the Bag class. It holds a list of numbers
 *   		and can manipulate (add/remove/sort/etc...) contents of the bag.
 *  
 */

#ifndef BAG_H
#define BAG_H

class	Bag
{
	public:
		static const size_t		CAPACITY = 1000; /// max bag size

		/**
		 *  Function:   Bag
		 *              default constructor. sets size to 0.
		 */
		Bag();
		/**
		 *  Function:   Bag
		 * 				constructor that gives a list of contents for the bag
		 */
		Bag(int list[], int size);
		/**
		 *  Function:   size
		 *              returns the size of the array
		 *
		 *  @param list - list of contents to initialize bag
		 *  @param size - size of that list
		 */
		size_t		size(void) const;
		/**
		 *  Function:   insert
		 *              inserts "value" to the end of the bag
		 *
		 *  @param value - value to be added
		 *  @return - true/false based on if the function was successful
		 */
		bool		insert(const int value);
		/**
		 *  Function:   erase
		 *              erases a single instance of "value" from the bag
		 *
		 *  @param value - value to be erased
		 *  @return - true/false based on if the function was successful
		 */
		bool		erase(const int value);
		/**
		 *  Function:   eraseAll
		 *              erases all instances of "value" from the bag
		 *
		 *  @param value - value to be erased
		 *  @return - true/false based on if the function was successful
		 */
		bool		eraseAll(const int value);
		/**
		 *  Function:   at
		 *              returns the value stored at index
		 *
		 *  @param index - position to find a value
		 *  @return - the value at the index. -9999 if it fails
		 */
		int			at(int index);
		/**
		 *  Function:   toString
		 *              returns the contents of the bag as a string
		 *              in the format "[1, 2, 3]"
		 *
		 *  @return - the string with the contents
		 */
		char		*toString(void);
		/**
		 *  Function:   sort
		 *              sorts the contents lowest to highest
		 */
		void		sort(void);
		/**
		 *  Function:   removeDuplicates
		 *              removes all duplicate values from the bag
		 */
		void		removeDuplicates(void);
		/**
		 *  Function:   howMany
		 *              counts how many instances of "value" are in the bag
		 *              current bag
		 *  @param value - value to be counted
		 *  @return - # of instances
		 */
		int			howMany(const int value) const;
		/**
		 *  Operator:   +=
		 *              adds contents of the given bag to this bag
		 *              current bag
		 *  @param other_bag - the bag to be added to this bag
		 */
		void		operator +=(const Bag &other_bag);
		/**
		 *  Operator:   ==
		 *              compares two bags and returns if they're equal
		 *  @param other_bag - the bag to be added to this bag
		 *  @return - true if they have the same contents, regardless of
		 *  			order
		 */
		bool		operator ==(const Bag &other_bag);
		/**
		 *  Operator:   <<
		 *              prints the bag's contents to the given stream
		 *  @param outs - file stream to print to
		 *  @param b - bag to be printed
		 *  @return - the file stream
		 */
		friend	ostream		&operator <<(ostream &outs, const Bag &b);

	private:
		int			data[CAPACITY];
		size_t		used;
};

#endif
