/*
 * Unit testing for the Bag class for final CS 2400 project
 */
//#define CATCH_CONFIG_RUNNER

#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include <iostream>
#include "catch.hpp"
#include "../bag.h"

using namespace std;
const int MAXSCORE = 35;
static int score = 0;

TEST_CASE("Testing  Bag Class") {
    SECTION("Default Constructor") {
        Bag a;
        REQUIRE(0 == a.size());
        score += 1;
    }
    SECTION("Constructor with Array") {
        int arr[] = {9, 8, 3, 2, 1, 7, 5};
        Bag a(arr, 7);
        REQUIRE("[9, 8, 3, 2, 1, 7, 5]" == a.toString());
        score += 5;
    }
    SECTION("Size function") {
        Bag a;
        REQUIRE(0 == a.size());

        score += 1;
    }
    SECTION("Insert function") {
        Bag a;
        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        REQUIRE(4 == a.size());
        REQUIRE("[10, 20, 30, 10]" == a.toString());
        score += 1;
    }

    SECTION("Erase function") {
        Bag a;
        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        a.erase(10);
        a.erase(10);
        a.sort();
        REQUIRE("[20, 30]" == a.toString());
        score += 1;
    }

    SECTION("EraseAll function") {
        Bag a;
        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        a.insert(10);
        a.insert(10);
        a.insert(10);
        a.insert(5);
        a.eraseAll(10);
        a.sort();
        REQUIRE("[5, 20, 30]" == a.toString());
        score += 1;
    }
    SECTION("At function") {
        Bag a;
        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        a.insert(10);
        a.insert(10);
        a.insert(10);
        a.insert(5);
        REQUIRE(10 == a.at(0));
        REQUIRE(30 == a.at(2));
        REQUIRE(5 == a.at(7));
        REQUIRE(-9999 == a.at(-1));
        REQUIRE(-9999 == a.at(100));
        
        score += 5;
    }
    SECTION("Overloaded == operator") {
        int arr1[] = {9, 8, 3, 2, 1, 7, 5};
        Bag a1(arr1, 7);

        int arr2[] = {9, 5, 3, 1, 2, 7, 8};
        Bag a2(arr2, 7);
        
        REQUIRE(true == (a1 == a2));
        Bag a3;
        REQUIRE(false == (a1 == a3));
        score += 5;
    }
    
   
    SECTION("Sort function") {
        Bag a;
        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        a.insert(25);
        a.insert(35);

        a.sort();
        REQUIRE("[10, 10, 20, 25, 30, 35]" == a.toString());
        score += 5;
    }
    
    SECTION("toString function") {
        Bag a;
        REQUIRE("[]" == a.toString());

        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        REQUIRE(4 == a.size());
        REQUIRE("[10, 20, 30, 10]" == a.toString());
        score += 5;
    }
    
    SECTION("removeDuplicates function") {
        Bag a;
        a.insert(10);
        a.insert(20);
        a.insert(30);
        a.insert(10);
        a.insert(10);
        a.insert(10);
        a.insert(10);
        a.insert(5);
        a.insert(5);
        a.insert(5);
        a.insert(99);
        
        a.removeDuplicates();
        a.sort();
        REQUIRE("[5, 10, 20, 30, 99]" == a.toString());
        score += 5;
    }

 

    SECTION("Score"){
        std::cout << "\033[1;35m" << "\n==========================================" << endl;
        std::cout << "\033[1;33m" <<  " Score: " << score << "/" << MAXSCORE << "\033[1;35m" << endl;
        // << " (passed " << testsPassed <<  " out of " << NUMTESTS << " tests)" << "\033[0m" << endl;
        std::cout << "==========================================\n" << "\033[0m" << endl;
    }
}

