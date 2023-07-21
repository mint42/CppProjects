/**
 *    @file: part.cc
 *  @author: Riley Reedy
 *    @date: 7/20/23
 *   @brief: Handling of the parts class.
 */

#include <iostream>
#include <string>

#include "part.h"
#include "transaction.h"

using namespace std;

Part::Part()
{
	name = "";
	id = 0;
	price = 0;
	quantity = 0;
	transactions = new Transaction[5];
}

Part::Part(const Part &other)
{
	if (capacity < other.capacity)
	{
		delete [] transactions;
		capacity = other.capacity;
		transactions = new Transaction[capacity];
	}

	name = other.name;
	id = other.id;
	price = other.price;
	quantity = other.quantity;
	num_transactions = other.num_transactions;

	for (size_t i = 0; i < num_transactions; ++i)
	{
		transactions[i].id = other.transactions[i].id;
		transactions[i].date = other.transactions[i].date;
		transactions[i].quantity = other.transactions[i].quantity;
	}
}

Part::~Part()
{
	delete [] transactions;
}

int		Part::get_transaction_by_date(string compare_date) const
{
		for (size_t i = 0; i < num_transactions; ++i)
		{
			if (transactions[i].date == compare_date)
				return (i);
		}
		return (-1);
		
}

int		Part::get_transaction_by_id(int compare_id) const
{
		for (size_t i = 0; i < num_transactions; ++i)
		{
			if (transactions[i].id == compare_id)
				return (i);
		}
		return (-1);
}

void			Part::add_transaction(string new_date, size_t new_quantity)
{
	if (num_transactions == capacity)
	{
		capacity = capacity + 5;
		Transaction	*new_transactions = new Transaction[capacity];

		for (size_t i = 0; i < num_transactions; ++i)
		{
			new_transactions[i].id = transactions[i].id;
			new_transactions[i].date = transactions[i].date;
			new_transactions[i].quantity = transactions[i].quantity;
		}
		delete [] transactions;
		transactions = new_transactions;
	}

	transactions[num_transactions - 1].id = num_transactions + 1000;
	transactions[num_transactions - 1].date = new_date;
	transactions[num_transactions - 1].quantity = new_quantity;
	++num_transactions;
}

void			Part::delete_transactions()
{
	delete [] transactions;
	num_transactions = 0;
}

string			Part::get_name() const
{
	string	name_copy;
	name_copy = name;
	return (name_copy);
}

int				Part::get_id() const
{
	return (id);
}

double			Part::get_price() const
{
	return (price);
}

size_t			Part::get_quantity() const
{
	return (quantity);
}
void			Part::set_name(string new_name)
{
	name = new_name;
}
void	  		Part::set_id(int new_id)
{
	id = new_id;
}
void			Part::set_price(double new_price)
{
	price = new_price;
}
void			Part::set_quantity(size_t new_quantity)
{
	quantity = new_quantity;
}

void			Part::operator=(const Part &other)
{
	if (capacity < other.capacity)
	{
		capacity = other.capacity;
		transactions = new Transaction[capacity];
	}

	name = other.name;
	id = other.id;
	price = other.price;
	quantity = other.quantity;
	capacity = other.capacity;
	num_transactions = other.num_transactions;
	delete [] transactions;
	transactions = new Transaction[capacity];

	for (size_t i = 0; i < num_transactions; ++i)
	{
		transactions[i].id = other.transactions[i].id;
		transactions[i].date = other.transactions[i].date;
		transactions[i].quantity = other.transactions[i].quantity;
	}
}

// friend ostream	&operator<<(ostream &outs, const Part &part)
// {
// 	outs << part.name << endl;
// 	outs << part.id << " " << part.price << " " part.quantity << endl;
// 
// 	for (size_t i = 0; i < part.num_transactions; ++i)
// 	{
// 		outs << (part.transactions[i]).id <<
// 		" " << (part.transactions[i]).date <<
// 		" " << (part.transactions[i]).quantity << endl;
// 	}
// }
