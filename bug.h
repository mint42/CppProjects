/**
 *   @file: bug.h
 * @author: Nasseef Abukamail
 *   @date: July 27, 2022
 *  @brief: Bug base class
 */

#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const size_t GRID_SIZE = 20;
class Bug{
public:
    Bug();
    

     size_t getRow() const{return row;}
     size_t getCol() const{return col;}
     size_t getSteps() const{return steps;};
    char getSymbol() const{return symbol;}

    void setRow(size_t r){row = r;}
    void setCol(size_t c){col = c;}
    void setSteps(size_t s){steps = s;}
    void setSymbol(char s){symbol = s;}
    char getSymbol(){return symbol;}
    virtual void move(Bug* grid[][GRID_SIZE]){};
    virtual ~Bug(){}
private:
    size_t steps;
    size_t row; //row location
    size_t col; //col location
    char symbol; //character to represent a bug
};


#endif