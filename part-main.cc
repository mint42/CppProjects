/**
 *    @file: parts-main.cc
 *  @author: Riley Reedy
 *    @date: 7/20/23
 *   @brief: Defining the Transaction struct
 *  
 */

#include <ios>
#include <iostream>
#include <fstream>
#include <string>

#include "part.h"

static void		display_menu()
{
	cout << "|------------------------------------------------------|" << endl;
	cout << "|                         MENU                         |" << endl;
	cout << "|------------------------------------------------------|" << endl;
	cout << "|      1. Print part's transaction info                |" << endl;
	cout << "|      2. Add a new transaction                        |" << endl;
	cout << "|      3. Search for a transaction by date             |" << endl;
	cout << "|      4. Search for a transaction by id               |" << endl;
	cout << "|      5. Delete all transactions.                     |" << endl;
	cout << "|      6. Save and Quit.                               |" << endl;
	cout << "|------------------------------------------------------|" << endl;
	cout << endl;
}

static void		load_transactions(Part *part, istream &ins)
{
	string			name;
	int				id;
	double			price;
	size_t			quantity;

	int				trans_id;
	string			trans_date;
	size_t			trans_quantity;

	ins >> name;
	part->set_name(name);

	ins >> id >> price >> quantity;
	part->set_id(id);
	part->set_price(price);
	part->set_quantity(quantity);

	while (!ins.eof())
	{
		ins >> trans_id >> trans_date >> trans_quantity;
		part->add_transaction(trans_date, trans_quantity);
	}
}

static void		unload_transactions(Part *part, ostream &outs)
{
	outs << part->get_name();
	outs << part->get_id() << part->get_price() << part->get_quantity();

	for (size_t i = 0; i < part->get_num_transactions(); ++i)
	{
		part->print_transaction(i, outs);
	}
}

int				main(int argc, char **argv)
{
	ifstream	ins;
	Part		*part;
	string		todays_date;
	int			command;

	if (argc != 2)
	{
		cout << "usage: ./a.out <filename>" << endl;
		return (0);
	}

	ins.open(argv[1], ios::in);
	if (ins.fail())
	{
		cout << "failed to open " << argv[1] << endl;
		return (0);
	}
	load_transactions(part, ins);
	ins.close();

	cout << "Please enter today's data (Format YYYY-MM-DD): ";
	cin >> todays_date;

	display_menu();

	while (1)
	{
		cout << "Please enter a command number: ";
		cin >> command;

		if (command == 1)
			unload_transactions(part, cout);
		if (command == 2)
		{
			size_t	quantity;

			cout << "How many parts would you like?: ";
			cin >> quantity;

			part->add_transaction(todays_date, quantity);
		}
		if (command == 3)
		{
			string	date;

			cout << "Please enter a date to search: ";
			cin >> date;

			part->search_transaction_by_date(todays_date);
		}
		if (command == 4)
		{
			int		id;

			cout << "Please enter a date to search: ";
			cin >> id;

			part->search_transaction_by_id(id);
		}
		if (command == 5)
			part->delete_transactions();
		if (command == 6)
		{
			ofstream	outs;;

			outs.open(argv[1], ios::out);
			if (outs.fail())
			{
				cout << "failed to open " << argv[1] << endl;
				return (0);
			}

			unload_transactions(part, outs);
			outs.close();
			break ;
		}
	}

	return (0);
}
