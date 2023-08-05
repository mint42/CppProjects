/**
 *   @file: main.cc
 * @author: Riley Reedy
 *   @date: 8-3-23
 *  @brief: Predator Pray game of wasps and ants.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "ant.h"
#include "bug.h"
#include "wasp.h"

using namespace std;

/// Constants and function prototypes
const size_t	NUM_WASPS = 5;
const size_t	NUM_ANTS = 100;
const char		COLOR_GREEN[] = "\e[1;32m";
const char		COLOR_RED[] = "\e[1;35m";
const char		COLOR_WHITE[] = "\e[m";

/*
 *	Function:		initializeGrid
 *					creates the grid with NUM_WASPS and NUM_ANTS to start
 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
 *	@return:		N/A
 */
void	initializeGrid(Bug *grid[][GRID_SIZE]);
/*
 *	Function:		displayGrid
 *					prints the grid to the screen in its current state
 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
 *	@return:		N/A
 */
void	displayGrid(Bug *grid[][GRID_SIZE]);
/*
 *	Function:		timeStep
 *					executes the next loop of actions for the bugs on the grid
 *	@param(grid):	a GRID_SIZE x GRID_SIZE play space for the game
 *	@return:		N/A
 */
void	timeStep(Bug *grid[][GRID_SIZE]);

int		main(int argc, char const* argv[])
{
	Bug		*grid[GRID_SIZE][GRID_SIZE];
	srand(time(nullptr));

	initializeGrid(grid);
	string	ans = "";

	displayGrid(grid);

//	do
//	{
//		displayGrid(grid);
//		timeStep(grid);
//		cout << "hit enter to move again, type n to quit: ";
//		getline(cin, ans);
//	} while (ans == "");
	
	//if you want, you run the simulation a certain number of times
	//uncomment the following
	/*
	displayGrid(grid);
	for (size_t i = 0; i < 1000; i++)
	{
		timeStep(grid);
	}
	displayGrid(grid);
	*/

	return (0);
}

static void	find_spot_for_bug(Bug *grid[][GRID_SIZE], size_t &row, size_t &col)
{
	do
	{
		row = rand() % GRID_SIZE;
		col = rand() % GRID_SIZE;
	} while (grid[row][col] != nullptr);
}

void		initializeGrid(Bug *grid[][GRID_SIZE])
{
	for (size_t r = 0; r < GRID_SIZE; ++r)
	{
		for (size_t c = 0; c < GRID_SIZE; ++c)
			grid[r][c] = nullptr;
	}

	size_t	row = 0;
	size_t	col = 0;

	for (size_t w = 0; w < NUM_WASPS; ++w)
	{
		find_spot_for_bug(grid, row, col);
		Wasp	*wasp = new Wasp(row, col);
		grid[row][col] = wasp;
	}

	for (size_t a = 0; a < NUM_ANTS; ++a)
	{
		find_spot_for_bug(grid, row, col);
		Ant		*ant = new Ant(row, col);
		grid[row][col] = ant;
	}
}

void	displayGrid(Bug *grid[][GRID_SIZE])
{
	char	aow; // meant to hold the ant or wasp symbol

	for (size_t r = 0; r < GRID_SIZE; ++r)
	{
		for (size_t c = 0; c < GRID_SIZE; ++c)
		{
			if (grid[r][c] == nullptr)
				cout << 'o';
			else
			{
				aow = grid[r][c]->getSymbol();
				if (aow == 'a')
					cout << COLOR_GREEN << aow << COLOR_WHITE;
				else
					cout << COLOR_RED << aow << COLOR_WHITE;
			}
			if (c < GRID_SIZE - 1)
				cout << " ";
		}
		cout << endl;
	}
}

void	timeStep(Bug *grid[][GRID_SIZE])
{
//	for (size_t i = 0; i < GRID_SIZE; ++i)
//	{
//		for (size_t j = 0; j < GRID_SIZE; ++j)
//		{
//			if (grid[row][col] == nullptr)
//				continue ;
//
//		}
//		cout << endl;
//	}
}
