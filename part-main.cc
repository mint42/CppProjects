/**
 *    @file: parts-main.cc
 *  @author: Riley Reedy
 *    @date: 7/20/23
 *   @brief: interface for parts and transactions
 */

#include <unistd.h>
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

static int		load_transactions(Part *part, ifstream &ins)
{
	string			name;
	int				id;
	double			price;
	size_t			quantity;

	int				trans_id;
	string			trans_date;
	size_t			trans_quantity;

	getline(ins, name);
	if (ins.eof())
		return (0);

	part->set_name(name);

	ins >> id >> price >> quantity;
	part->set_id(id);
	part->set_price(price);
	part->set_quantity(quantity);

	while (!ins.eof())
	{
		ins >> trans_id;
		if (ins.eof())
			return (1);
		ins >> trans_date >> trans_quantity;
		part->add_transaction(trans_date, trans_quantity, 1);
	}
	return (1);
}

static void		unload_transactions(Part *part, ofstream &outs)
{
	outs << part->get_name() << endl;
	outs << part->get_id() << " " << part->get_price() << " " << part->get_quantity() << endl;

	for (size_t i = 0; i < part->get_num_transactions(); ++i)
	{
		part->print_transaction(i, outs);
	}
}

static void		print_transactions_pretty(Part *part)
{
	cout << "--------------------------------------------------------" << endl;
	cout << "          Part NAME: " << part->get_name() << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Part ID: " << part->get_id() << endl;
	// cout.set_width(fixe == fixed;
	cout << "Price: $" << part->get_price() << endl;
	cout << "Quantity: " << part->get_quantity() << endl;
	cout << "--------------------------------------------------------" << endl;

	for (size_t i = 0; i < part->get_num_transactions(); ++i)
	{
		part->print_transaction(i, cout);
	}
	cout << "--------------------------------------------------------" << endl;
}

int				main(int argc, char **argv)
{
	ifstream	ins;
	Part		*part = new Part();
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

	if (load_transactions(part, ins) == 0)
	{
		cout << "No data to load. Please provide a non empty input file." << endl;
		return (0);
	}
	ins.close();

	cout << "Please enter today's data (Format YYYY-MM-DD): ";
	cin >> todays_date;

	display_menu();

	while (1)
	{

		cout << endl << "Please enter a command number: ";
		cin >> command;

		if (command == 1)
			print_transactions_pretty(part);
		if (command == 2)
		{
			size_t	quantity;

			cout << "How many parts would you like?: ";
			cin >> quantity;

			part->add_transaction(todays_date, quantity, 0);
		}
		if (command == 3)
		{
			string	date;

			cout << "Please enter a transaction date to search: ";
			cin >> date;

			part->search_transaction_by_date(date);
		}
		if (command == 4)
		{
			int		id;

			cout << "Please enter a transaction id to search: ";
			cin >> id;

			part->search_transaction_by_id(id);
		}
		if (command == 5)
			part->delete_transactions();
		if (command == 6)
		{
			ofstream	outs;

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

	delete part;

	return (0);
}
