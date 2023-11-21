/**
 *   @file: wasp.h
 * @author: Riley Reedy
 *   @date: 8-5-23
 *  @brief: Wasp class implementation.
 */

#ifndef WASP_H
# define WASP_H

# include "bug.h"

using namespace std;

# define STEPS_TIL_WASP_STARVE	3
# define STEPS_TIL_WASP_BREED	8

class			Wasp : public Bug
{
	public:
		/*
		 *	Constructor:	default
		 *					sets steps, rows and columns to 0
		 */
		Wasp();
		/*
		 *	Constructor:
		 *					sets steps to 0, and rows and columns to
		 *					the given parameters
		 *	@param(newR):	row position
		 *	@param(newC):	col position
		 */
		Wasp(size_t newR, size_t newC);
		/*
		 *	Function:		move
		 *					moves a bug	(Up Down Left or Right) in a random 
		 *					direction. eats any ants in that spot.
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@return:		N/A
		 */
		void	move(Bug *grid[][GRID_SIZE]);
		/*
		 *	Function:		breed
		 *					creates a new bug beside the original after a certain
		 *					step criteria is met (8 steps) and there is space
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@return:		N/A
		 */
		void	breed(Bug *grid[][GRID_SIZE]);
		/*
		 *	Function:	getStarve
		 *				returns the number of time steps the bug has survived
		 *				since last eating
		 *	@param():	N/A
		 *	@return:	number of steps
		 */
		size_t	getStarve();

	private:
		size_t	starve; 
};

Wasp::Wasp() : Bug()
{
	starve = 0;
	setSymbol(WASP_SYMBOL);
}

Wasp::Wasp(size_t newR, size_t newC) : Bug()
{
	starve = 0;
	setRow(newR);
	setCol(newC);
	setSymbol(WASP_SYMBOL);
}

void	Wasp::move(Bug *grid[][GRID_SIZE])
{
	size_t	row = this->getRow();
	size_t	col = this->getCol();
	size_t	newR = row;
	size_t	newC = col;

	this->setSteps(this->getSteps() + 1);
  	this->choose_new_random_spot(newR, newC);
	// don't move because border or another wasp
	if ((newR == row && newC == col) ||
  		(grid[newR][newC] != nullptr && grid[newR][newC]->getSymbol() == WASP_SYMBOL))
  	{
  		++starve;
		return ;
  	}
	// can move but no food
	if (grid[newR][newC] == nullptr)
		++starve;
	// can move and eat
	else if (grid[newR][newC]->getSymbol() == ANT_SYMBOL)
	{
		delete grid[newR][newC];
		grid[newR][newC] = this;
		starve = 0;
	}
	// set coordinates
	this->setRow(newR);
	this->setCol(newC);
	// move to the new spot
	grid[newR][newC] = this;
	grid[row][col] = nullptr;
}

void	Wasp::breed(Bug *grid[][GRID_SIZE])
{
	size_t	row = this->getRow();
	size_t	col = this->getCol();
	size_t	newR = row;
	size_t	newC = col;

	if (this->getSteps() < STEPS_TIL_WASP_BREED)
		return ;
	this->choose_new_free_spot(grid, newR, newC);
	// breed only if there is a free spot
	if (newR != row || newC != col)
	{
		Wasp	*new_wasp = new Wasp(newR, newC);
		grid[newR][newC] = new_wasp;
		this->setSteps(0);
	}
}

size_t	Wasp::getStarve()
{
	return (starve);
}

#endif
