/**
 *    @file: part.h
 *  @author: Riley Reedy
 *    @date: 7/19/23
 *   @brief: Enter a detailed description of the program/file
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
		 * Initializes the id to 0 and the name to "N/A"
		 */
		Part();
		Part(const Part &other_part);
		~Part();

		int				get_transaction_by_date(string compare_date) const;
		int				get_transaction_by_id(int compare_id) const;
		void			add_transaction(string new_date, size_t new_quantity);
		void			delete_transactions();

		string			get_name() const;
		int				get_id() const;
		double			get_price() const;
		size_t			get_quantity() const;
		void			set_name(string new_name);
		void	  		set_id(int new_id);
		void			set_price(double new_price);
		void			set_quantity(size_t new_quantity);

		void			operator=(const Part &part);
		friend ostream	&operator<<(ostream &outs, const Part &the_part);

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
