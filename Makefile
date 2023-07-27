# Created by: Nasseef Abukamail
# This Makefile will run tests for the bag class
# The tests will run automatically GitHub Actions
# This is to test continuous integration (CI).
# Usage for Mac and Windows:
#    make run_tests  (mac and linux)
#    mingw32-make run_tests_win
#
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.out: dlist.h dnode.h
	$(CC) $(CFLAGS) dlist-main.cc -o a.out


######################################## R U N   T E S T s ##################################################
run_tests: 
	head dlist.h
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc -o _TEST/run_tests ; _TEST/run_tests -sr compact

run_tests_win: 
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc -o _TEST/run_tests
	_TEST/run_tests -sr compact
##############################################################################################################

clean:
	rm -rf _TEST/*.o _TEST/run_tests a.out