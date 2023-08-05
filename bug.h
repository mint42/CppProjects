/**
 *   @file: bug.h
 * @author: Riley Reedy
 *   @date: 8-5-23
 *  @brief: Bug base class
 */

#ifndef BUG_H
# define BUG_H

# include <iostream>
# include <iomanip>
# include <cstdlib>
using namespace std;

const size_t	GRID_SIZE = 20;

class					Bug
{
	public:
						Bug()
						{
							steps = 0;
							row = 0;
							col = 0;
							symbol = 'b';
						}
		virtual			~Bug(){}

		size_t			getRow() const{return row;}
		size_t			getCol() const{return col;}
		size_t			getSteps() const{return steps;};
		char			getSymbol() const{return symbol;}
		char			getSymbol(){return symbol;}

		void			setRow(size_t r){row = r;}
		void			setCol(size_t c){col = c;}
		void			setSteps(size_t s){steps = s;}
		void			setSymbol(char s){symbol = s;}
//		virtual void	move(Bug *grid[][GRID_SIZE]){};

	private:
		size_t			steps;
		size_t			row; //row location
		size_t			col; //col location
		char			symbol; //character to represent a bug
};

#endif
