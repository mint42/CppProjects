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
		Wasp();
		Wasp(size_t newR, size_t newC);

		void	move(Bug *grid[][GRID_SIZE]);
		void	breed(Bug *grid[][GRID_SIZE]);
		size_t	getStarve();

	private:
		size_t	starve; 
};

Wasp::Wasp() : Bug()
{
	starve = 0;
	setSymbol('w');
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
		starve = 0;
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
