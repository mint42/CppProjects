#
#   @file: Makefile
# @author: Riley Reedy
#   @date: 7/20/23
#  @brief: oversees building and deleting the program
#

CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.out: part.o part.h part-main.o
	$(CC) $(CFLAGS) part.o part-main.o -o a.out

parts.o: part.cc part.h
	$(CC) -c $(CFLAGS) part.cc

parts-main.o: part-main.cc part.h
	$(CC) -c $(CFLAGS) part-main.cc

######################################## R U N   T E S T s ##################################################
run_tests: 
	head part.cc
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc part.cc -o _TEST/run_tests ; _TEST/run_tests -sr compact
##############################################################################################################

clean:
	rm -rf _TEST/*.o _TEST/run_tests a.out
