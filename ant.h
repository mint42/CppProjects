/**
 *   @file: ant.h
 * @author: Riley Reedy
 *   @date: 8-5-23
 *  @brief: Ant class prototypes and descriptions.
 */

#ifndef ANT_H
# define ANT_H

# include "bug.h"

# define STEPS_TIL_ANT_BREED 3

using namespace std;

class			Ant : public Bug
{
	public:
		Ant();
		Ant(size_t newR, size_t newC);
		void	move(Bug* grid[][GRID_SIZE]);
		void	breed(Bug* grid[][GRID_SIZE]);
};

Ant::Ant() : Bug()
{
	setSymbol('a');
}

Ant::Ant(size_t newR, size_t newC) : Bug()
{
	setRow(newR);
	setCol(newC);
	setSymbol('a');
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
