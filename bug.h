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
				Bug();
		virtual	~Bug(){};

		size_t	getRow() const;
		size_t	getCol() const;
		size_t	getSteps() const;
		char	getSymbol() const;

		void	setRow(size_t r);
		void	setCol(size_t c);
		void	setSteps(size_t s);
		void	setSymbol(char s);

		void	choose_new_random_spot(size_t &newR, size_t &newC);
		void	choose_new_free_spot(Bug *grid[][GRID_SIZE], size_t &newR, size_t &newC);
		virtual void	move(Bug *grid[][GRID_SIZE]){};
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
