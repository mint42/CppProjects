/**
 *   @file: wasp.h
 * @author: Nasseef Abukamail
 *   @date: July 28, 2022
 *  @brief: Wasp class
 */
#ifndef WASP_H
#define WASP_H

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "bug.h"
using namespace std;

class Wasp : public Bug {
   public:
    Wasp() : Bug(){};
    Wasp(size_t newR, size_t newC) : Bug(){};
    void move(Bug* grid[][GRID_SIZE]);
    void breed(Bug* grid[][GRID_SIZE]);
   
   private:
    size_t starve; 
};


#endif  // WASP_H