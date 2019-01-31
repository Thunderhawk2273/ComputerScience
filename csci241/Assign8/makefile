
# PROGRAM:    assign2
# PROGRAMMER: William Freriks
# LOGON ID:   z1698749
# DATE DUE:   2/12/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall -ggdb

# Rule to link object code files to create executable file
assign8: source.o
	g++ $(CCFLAGS) -o assign8 source.o

# Rules to compile source code files to object code
source.o: source.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c source.cpp


# Pseudo-target to remove object code and executable files

clean:
	rm *.o 
	rm assign8
