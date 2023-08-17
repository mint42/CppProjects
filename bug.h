/**
 *   @file: bug.h
 * @author: Riley Reedy
 *   @date: 8-5-23
 *  @brief: Bug base class implementation.
 */

#ifndef BUG_H
# define BUG_H

using namespace std;

// critters
# define WASP_SYMBOL '%'
# define ANT_SYMBOL ';'
# define BUG_SYMBOL '*' // not needed, just for fun

const size_t	GRID_SIZE = 20;

class			Bug
{
	public:
		/*
		 *	Constructor:	default
		 *					sets steps, rows and columns to 0
		 */
				Bug();
		/*
		 *	Destructor:		default (virtual)
		 *					does nothing
		 */
		virtual	~Bug(){};

		/*
		 *	Function:	getRow
		 *				returns the row of the bug on the grid
		 *	@param():	N/A
		 *	@return:	the row
		 *
		 */
		size_t	getRow() const;
		/*
		 *	Function:	getCol
		 *				returns the column of the bug on the grid
		 *	@param():	N/A
		 *	@return:	the column
		 *
		 */
		size_t	getCol() const;
		/*
		 *	Function:	getSteps
		 *				returns the number of time steps the bug has survived
		 *				since last breeding
		 *	@param():	N/A
		 *	@return:	number of steps
		 *
		 */
		size_t	getSteps() const;
		/*
		 *	Function:	getSymbol
		 *				returns the symbol of the bug. Defined in bug.h
		 *	@param():	N/A
		 *	@return:	the symbol
		 *
		 */
		char	getSymbol() const;
		/*
		 *	Function:	setRow
		 *				changes the row variable
		 *	@param(r):	new row
		 *	@return:	N/A
		 */
		void	setRow(size_t r);
		/*
		 *	Function:	setCol
		 *				changes the column variable
		 *	@param(c):	new column
		 *	@return:	N/A
		 */
		void	setCol(size_t c);
		/*
		 *	Function:	setSteps
		 *				changes the number of steps 
		 *	@param(s):	new step count
		 *	@return:	N/A
		 */
		void	setSteps(size_t s);
		/*
		 *	Function:	setSymbol
		 *				changes the symbol of the bug
		 *	@param(s):	new symbol
		 *	@return:	N/A
		 */
		void	setSymbol(char s);

		/*
		 *	Function:		choose_new_random_spot
		 *					chooses a spot for the bug to move to
		 *					(Up Down Left or Right) and returns the coordinates using
		 *					references to the original position. nothing is changed
		 *					if the bug chooses to move towards a border. does
		 *					not consider if the space is occupied.
		 *	@param(newR):	comes in as the bug's original row and is updated
		 *					to the new row if applicable.
		 *	@param(newC):	comes in as the bug's original column and is updated
		 *					to the new column if applicable.
		 *	@return:	N/A
		 */
		void	choose_new_random_spot(size_t &newR, size_t &newC);
		/*
		 *	Function:		choose_new_free_spot
		 *					chooses a random free spot for the bug to move to
		 *					(Up Down Left or Right) and returns the coordinates using
		 *					references to the original position. nothing is changed
		 *					if there's no free space available.
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@param(newR):	comes in as the bug's original row and is updated
		 *					to the new row if applicable.
		 *	@param(newC):	comes in as the bug's original column and is updated
		 *					to the new column if applicable.
		 *	@return:	N/A
		 */
		void	choose_new_free_spot(Bug *grid[][GRID_SIZE], size_t &newR, size_t &newC);
		/*
		 *	Function:		move (virtual)
		 *					moves a bug	(Up Down Left or Right)
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@return:	N/A
		 */
		virtual void	move(Bug *grid[][GRID_SIZE]){};
		/*
		 *	Function:		breed (virtual)
		 *					creates a new bug beside the original after a certain
		 *					step criteria is met and there is space
 		 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
		 *	@return:	N/A
		 */
		virtual void	breed(Bug *grid[][GRID_SIZE]){};

	private:
		size_t	steps; // number of timesteps survived
		size_t	row; //row location
		size_t	col; //col location
		char	symbol; //character to represent a bug
};

# define UP		0
# define DOWN	1
# define LEFT	2
# define RIGHT	3

Bug::Bug()
{
	steps = 0;
	row = 0;
	col = 0;
	symbol = BUG_SYMBOL;
}

size_t	Bug::getRow() const{return row;}
size_t	Bug::getCol() const{return col;}
size_t	Bug::getSteps() const{return steps;};
char	Bug::getSymbol() const{return symbol;}

void	Bug::setRow(size_t r){row = r;}
void	Bug::setCol(size_t c){col = c;}
void	Bug::setSteps(size_t s){steps = s;}
void	Bug::setSymbol(char s){symbol = s;}

void	Bug::choose_new_random_spot(size_t &newR, size_t &newC)
{
	size_t	direction = rand() % 4;

	if (direction == UP && newR != 0)
		--newR;
	else if (direction == DOWN && newR != GRID_SIZE - 1)
		++newR;
	else if (direction == LEFT && newC != 0)
		--newC;
	else if (direction == RIGHT && newC != GRID_SIZE - 1)
		++newC;
}

void	Bug::choose_new_free_spot(Bug *grid[][GRID_SIZE], size_t &newR, size_t &newC)
{
	size_t	direction = rand() % 4;
	size_t	oldR = newR;
	size_t	oldC = newC;

	// starts in a random direction but checks all 4 spot or until a free spot is found
	for (size_t i = 0; i < 4 && oldR == newR && oldC == newC; ++i)
	{
		if (direction == UP && newR != 0 && grid[newR - 1][newC] == nullptr)
			--newR;
		else if (direction == DOWN && newR != GRID_SIZE - 1 && grid[newR + 1][newC] == nullptr)
			++newR;
		else if (direction == LEFT && newC != 0 && grid[newR][newC - 1] == nullptr)
			--newC;
		else if (direction == RIGHT && newC != GRID_SIZE - 1 && grid[newR][newC + 1] == nullptr)
			++newC;

		if (direction == UP)
			direction = RIGHT;
		else
			--direction;
	}
}

#endif
