/**
 *    @file: transaction.h
 *  @author: Riley Reedy
 *    @date: 7/19/23
 *   @brief: Defining the Transaction struct
 *  
 */

#ifndef TRANSACTION_H
# define TRANSACTION_H

#include <string>

using namespace std;

struct		Transaction
{
	int		id;
	string	date;
	size_t	quantity;
};

#endif
