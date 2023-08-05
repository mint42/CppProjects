/**
 *   @file: wasp.h
 * @author: Riley Reedy
 *   @date: 8-5-23
 *  @brief: Wasp class
 */

#ifndef WASP_H
# define WASP_H

# include <cstdlib>
# include <iomanip>
# include <iostream>

# include "bug.h"
using namespace std;

class			Wasp : public Bug
{
	public:
				Wasp() : Bug()
				{
					starve = 0;
					setSymbol('w');
				}
				Wasp(size_t newR, size_t newC) : Bug()
				{
					starve = 0;
					setRow(newR);
					setCol(newC);
					setSymbol('w');
				}
//		void	move(Bug* grid[][GRID_SIZE]);
//		void	breed(Bug* grid[][GRID_SIZE]);

	private:
		size_t	starve; 
};

#endif
