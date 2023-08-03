/*
 * Unit testing for the Bag class for final CS 2400 project
 */
//#define CATCH_CONFIG_RUNNER

#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include <iostream>
#include "catch.hpp"
#include "../dlist.h"

using namespace std;
const int MAXSCORE = 31;
static int score = 0;

TEST_CASE("Testing  DList Class") {
    SECTION("Default Constructor") {
        DList<int> myList;
        REQUIRE(0 == myList.length());
        REQUIRE(nullptr == myList.listHead());
        
        DList<string> names;
        names.headInsert("Jack");
        names.headInsert("Janet");
        names.headInsert("Chrissy");
        REQUIRE(3 == names.length());
        score += 1;
    }

    SECTION("headInsert") {
        DList<int> myList;

        myList.headInsert(50);
        myList.headInsert(40);
        myList.headInsert(30);
        myList.headInsert(20);
        myList.headInsert(10);
        DNode<int> *temp = myList.listHead()->getNext()->getNext();
        DNode<int> *temp2 = myList.search(30);
        REQUIRE(temp == temp2);
        REQUIRE(30 == temp2->getData());
        REQUIRE(20 == temp2->getPrevious()->getData());
        REQUIRE(40 == temp2->getNext()->getData());

        score += 1;
    }
    SECTION("Search") {
        DList<int> myList;

        myList.headInsert(50);
        myList.headInsert(40);
        myList.headInsert(30);
        myList.headInsert(20);
        myList.headInsert(10);
        
        DNode<int> *temp2 = myList.search(10);
        REQUIRE(10 == temp2->getData());
        temp2 = myList.search(999);
        REQUIRE(nullptr == temp2);
        temp2 = myList.search(50);
        REQUIRE(50 == temp2->getData());
        score += 1;
    }
    SECTION("InsertAfter") {
        DList<int> myList;

        myList.headInsert(50);
        myList.headInsert(40);
        myList.headInsert(30);
        myList.headInsert(20);
        myList.headInsert(10);
        
        DNode<int> *temp2 = myList.search(10);
        myList.insertAfter(temp2, 55);

        REQUIRE(55 == temp2->getNext()->getData());

        temp2 = myList.search(50);
        myList.insertAfter(temp2, 55);

        REQUIRE(55 == temp2->getNext()->getData()); 
        
        score += 1;
    }

    SECTION("DeleteNode") {
        DList<int> myList;

        myList.headInsert(50);
        myList.headInsert(40);
        myList.headInsert(30);
        myList.headInsert(20);
        myList.headInsert(10);
        
        DNode<int> *temp2 = myList.search(20);
        
        myList.deleteNode(temp2);
        REQUIRE(30 == myList.listHead()->getNext()->getData());

        temp2 = myList.search(10);
        
        myList.deleteNode(temp2);
        REQUIRE(30 == myList.listHead()->getData());
        
        
        myList.deleteNode(myList.listHead());
        myList.deleteNode(myList.listHead());
        myList.deleteNode(myList.listHead());
        REQUIRE(nullptr == myList.listHead());
        score += 1;
    }


    SECTION("numOccurrences") {
        DList<int> myList;

        myList.headInsert(50);
        myList.headInsert(40);
        myList.headInsert(30);
        myList.headInsert(30);
        myList.headInsert(30);
        myList.headInsert(30);
        myList.headInsert(20);
        myList.headInsert(10);
        myList.headInsert(10);
        REQUIRE(0 == myList.numOccurrences(99));
        REQUIRE(4 == myList.numOccurrences(30));
        REQUIRE(2 == myList.numOccurrences(10));
        score += 1;
    }

 SECTION("Iterator") {
        DList<int> myList;

        myList.headInsert(50);
        myList.headInsert(40);
        myList.headInsert(30);
        myList.headInsert(20);
        myList.headInsert(10);
        auto it = myList.begin();
        REQUIRE(10 == *it);
    
        it++;
        REQUIRE(20 == *it);
        ++it;
        REQUIRE(30 == *it);
        --it;
        REQUIRE(20 == *it);
        it--;
        REQUIRE(10 == *it);

        string values = "";
        for (auto it = myList.begin(); it != myList.end(); it++)
        {
            values += to_string(*it);
        }
        REQUIRE("1020304050" == values);

        auto it1 = myList.begin();
        auto it2 = myList.begin();
        REQUIRE(true == (it1 == it2));
        it2++;
        REQUIRE(true == (it2 != it1));
        score += 25;
    }

    SECTION("Score"){
        std::cout << "\033[1;35m" << "\n==========================================" << endl;
        std::cout << "\033[1;33m" <<  " Score: " << score << "/" << MAXSCORE << "\033[1;35m" << endl;
        // << " (passed " << testsPassed <<  " out of " << NUMTESTS << " tests)" << "\033[0m" << endl;
        std::cout << "==========================================\n" << "\033[0m" << endl;
    }
}

