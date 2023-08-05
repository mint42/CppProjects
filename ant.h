/**
 *   @file: ant.h
 * @author: Riley Reedy
 *   @date: 8-5-23
 *  @brief: Ant class
 */

#ifndef ANT_H
# define ANT_H

# include <cstdlib>
# include <iomanip>
# include <iostream>

# include "bug.h"
using namespace std;

class			Ant : public Bug
{
	public:
				Ant() : Bug()
				{
					setSymbol('a');
				}
				Ant(size_t newR, size_t newC) : Bug()
				{
					setRow(newR);
					setCol(newC);
					setSymbol('a');
				}
//		void	move(Bug* grid[][GRID_SIZE]);
//		void	breed(Bug* grid[][GRID_SIZE]);
};

#endif  // ANT_H
