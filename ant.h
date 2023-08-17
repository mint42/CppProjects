/**
 *   @file: ant.h
 * @author: Riley Reedy
 *   @date: 8-17-23
 *  @brief: Ant class implementation.
 */

#ifndef ANT_H
# define ANT_H

# include "bug.h"

# define STEPS_TIL_ANT_BREED 3

using namespace std;

class			Ant : public Bug
{
	public:
		/*
		 *	Constructor:	default
		 *					sets steps, rows and columns to 0
		 */
		Ant();
		/*
		 *	Constructor:
		 *					sets steps to 0, and rows and columns to
		 *					the given parameters
		 *	@param(newR):	row position
		 *	@param(newC):	col position
		 */
		Ant(size_t newR, size_t newC);
		/*
		 *	Function:		move
		 *					moves a bug	(Up Down Left or Right) in a ramdom 
		 *					direction if there's space
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@return:		N/A
		 */
		void	move(Bug* grid[][GRID_SIZE]);
		/*
		 *	Function:		breed
		 *					creates a new bug beside the original after a certain
		 *					step criteria (3 steps) is met and there is space
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@return:		N/A
		 */
		void	breed(Bug* grid[][GRID_SIZE]);
};

Ant::Ant() : Bug()
{
	setSymbol(ANT_SYMBOL);
}

Ant::Ant(size_t newR, size_t newC) : Bug()
{
	setRow(newR);
	setCol(newC);
	setSymbol(ANT_SYMBOL);
}

void	Ant::move(Bug *grid[][GRID_SIZE])
{
	size_t	row = this->getRow();
	size_t	col = this->getCol();
	size_t	newR = row;
	size_t	newC = col;

	this->setSteps(this->getSteps() + 1);
  	this->choose_new_random_spot(newR, newC);
	// only move if not border and spot is free
	if ((newR != row || newC != col) && (grid[newR][newC] == nullptr))
  	{
		// set coordinates
		this->setRow(newR);
		this->setCol(newC);
		// move to the new spot
		grid[newR][newC] = this;
		grid[row][col] = nullptr;
		return ;
  	}
}

void	Ant::breed(Bug *grid[][GRID_SIZE])
{
	size_t	row = this->getRow();
	size_t	col = this->getCol();
	size_t	newR = row;
	size_t	newC = col;

	if (this->getSteps() < STEPS_TIL_ANT_BREED)
		return ;
	this->choose_new_free_spot(grid, newR, newC);
	// breed only if there is a free spot
	if (newR != row || newC != col)
	{
		Ant	*new_ant = new Ant(newR, newC);
		grid[newR][newC] = new_ant;
		this->setSteps(0);
	}
}

#endif
