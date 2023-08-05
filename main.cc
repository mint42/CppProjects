/**
 *   @file: predator-prey.cc
 * @author: Nasseef Abukamail
 *   @date: July 28, 2022
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
const size_t NUM_WASPS = 5;
const size_t NUM_ANTS = 100;

void initializeGrid(Bug* grid[][GRID_SIZE]);
void displayGrid(Bug* grid[][GRID_SIZE]);
void timeStep(Bug* grid[][GRID_SIZE]);

int main(int argc, char const* argv[]) {
    Bug* grid[GRID_SIZE][GRID_SIZE];
    srand(time(nullptr));

    initializeGrid(grid);
    string ans = "";
    do
    {
        displayGrid(grid);
        timeStep(grid);
        cout << "hit enter to move again, type n to quit: ";
        getline(cin, ans);
    } while (ans == "");
    
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
    return 0;
}  /// main

