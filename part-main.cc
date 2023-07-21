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

static void		load_transactions(Part *part, istream *file)
{
	int	 i = 0;
}
static void		unload_transactions(Part *part, ostream *file)
{
	int	 i = 0;
}

int				main(int argc, char **argv)
{
	ifstream	*file_in;
	Part		*part;
	string		todays_date;
	int			command;

	if (argc != 2)
	{
		cout << "usage: ./a.out <filename>" << endl;
		return (0);
	}

	file_in->open(argv[1], ios::in);
	if (file_in->fail())
	{
		cout << "failed to open " << argv[1] << endl;
		return (0);
	}
	load_transactions(part, file_in);
	file_in->close();

	cout << "Please enter today's data (Format YYYY-MM-DD): ";
	cin >> todays_date;

	display_menu();

	while (1)
	{
		cout << "Please enter a command number: ";
		cin >> command;

		if (command == 1)
			unload_transactions(part, &cout);
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

			part->get_transaction_by_date(todays_date);
		}
		if (command == 4)
		{
			int		id;

			cout << "Please enter a date to search: ";
			cin >> id;

			part->get_transaction_by_id(id);
		}
		if (command == 5)
			part->delete_transactions();
		if (command == 6)
		{
			ofstream	*file_out;

			file_out->open(argv[1], ios::out);
			if (file_out->fail())
			{
				cout << "failed to open " << argv[1] << endl;
				return (0);
			}

			unload_transactions(part, file_out);
			file_out->close();
			break ;
		}
	}

	return (0);
}
