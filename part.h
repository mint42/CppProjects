/**
 *    @file: part.h
 *  @author: Riley Reedy
 *    @date: 7/19/23
 *   @brief: prototypes and desctriptions for the Part class
 *  
 */

#ifndef PART_H
#define PART_H

#include "transaction.h"

using namespace std;

class	Part
{
	public:
		/** Default constructor
		 * sets all info variables to 0.
		 * creates a transaction array with a capacity of 5
		 */
		Part();
		/** 
		 * Copy constructor
		 * copys one part object to another
		 */
		Part(const Part &other_part);
		/** 
		 * Descructor
		 * deletes transaction array
		 */
		~Part();

		/*
		 *	Function:	search_transactions_by_data
		 *				searches and prints all transactions that match the
		 *				given date
		 *	@param - compare_date - date string to compare to
		 *	@return - na
		 */
		void			search_transaction_by_date(string compare_date) const;
		/*
		 *	Function:	search_transactions_by_id
		 *				searches and prints all transactions that match the
		 *				given id
		 *	@param - compare_id - id to compare to
		 *	@return - na
		 */
		void			search_transaction_by_id(int id) const;
		/*
		 *	Function:	print_transaction
		 *				prints a single transaction line with the given index
		 *				to the array to an outstream
		 *	@param - index - index in the transaction array
		 *	@param - outs - outstream
		 *	@return - na
		 */
		void			print_transaction(int index, ostream &outs) const;
		/*
		 *	Function:	add_transaction
		 *				adds a new transaction to the history
		 *	@param - new_date - date for transaction struct
		 *	@param - new_quantity - quantity for transaction struct
		 *	@param - from file - checks if this is loading old transaction
		 *				or adding new one. matters for the quantity count
		 *	@return - na
		 */
		void			add_transaction(string new_date, size_t new_quantity, int from_file);
		/*
		 *	Function:	delete_transactions
		 *				deletes entire transaction history
		 *	@return - na
		 */
		void			delete_transactions();

		/*	get_name
		 *	@return - the name of the part
		 */
		string			get_name() const;
		/*	get_id
		 *	@return - the part id
		 */
		int				get_id() const;
		/*	get_price
		 *	@return - part price
		 */
		double			get_price() const;
		/*	get_quantity
		 *	@return - number of items in stock
		 */
		size_t			get_quantity() const;
		/*	get_num_transactions
		 *	@return - number of transactions in the history
		 */
		size_t			get_num_transactions() const;
		/*	set_name
		 *	@param - new_name - set part to new name
		 */
		void			set_name(string new_name);
		/*	set_id
		 *	@param - new_id - set new part id
		 */
		void	  		set_id(int new_id);
		/*	set_price
		 *	@param - new_price - set new part price
		 */
		void			set_price(double new_price);
		/*	set_price
		 *	@param - new_quantity - set new quantity
		 */
		void			set_quantity(size_t new_quantity);

		/*	operator=
		 *	set 'this' to part
		 */
		void			operator=(const Part &part);

	private:
		string			name;
		int				id;
		double			price;
		size_t			quantity;
		size_t			num_transactions;
		size_t			capacity;
		Transaction		*transactions;
};

#endif
