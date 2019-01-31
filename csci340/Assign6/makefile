#
# PROGRAM:    Assignment 5
# PROGRAMMER: William Freriks
# LOGON ID:   z1698749
# DATE DUE:   10/1/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment6.exe: assignment5.o assignment6.o
	g++ $(CCFLAGS) -o assignment5.exe assignment6main.cc assignment5.o assignment6.o

# Rules to compile source code files to object code
assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc


assignment6.o: assignment6.cc assignment6.h
	g++ $(CCFLAGS) -c assignment6.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6.exe

