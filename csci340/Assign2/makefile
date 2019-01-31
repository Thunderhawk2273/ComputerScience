#
# PROGRAM:    assign2
# PROGRAMMER: William Freriks
# LOGON ID:   z1698749
# DATE DUE:   2/12/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment2.exe: assignment2.o
	g++ $(CCFLAGS) -o assignment2.exe assignment2.o

# Rules to compile source code files to object code
assignment2.o: assignment2.cc
	g++ $(CCFLAGS) -c assignment2.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment2.exe

