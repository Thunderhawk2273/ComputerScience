
# PROGRAM:    assign6
# PROGRAMMER: William Freriks
# LOGON ID:   
# DATE DUE:   2/12/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign6: source.o Queue.o
	g++ $(CCFLAGS) -o assign6 source.o Queue.o

# Rules to compile source code files to object code
source.o: source.cpp Queue.h
	g++ $(CCFLAGS) -c source.cpp

Queue.o: Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp


# Pseudo-target to remove object code and executable files

clean:
	rm *.o assign6
