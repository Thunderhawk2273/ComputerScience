
# PROGRAM:    assign2
# PROGRAMMER: William Freriks
# LOGON ID:   z1698749
# DATE DUE:   2/12/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall -ggdb

# Rule to link object code files to create executable file
assign9: source.o shape.o circle.o rectangle.o triangle.o
	g++ $(CCFLAGS) -o assign9 source.o shape.o circle.o rectangle.o triangle.o

# Rules to compile source code files to object code

triangle.o: triangle.cpp triangle.h shape.h
	g++ $(CCGLAGS) -c triangle.cpp

rectangle.o: rectangle.cpp rectangle.h shape.h
	g++ $(CCGLAGS) -c rectangle.cpp

circle.o: circle.cpp circle.h shape.h
	g++ $(CCGLAGS) -c circle.cpp

shape.o: shape.cpp shape.h
	g++ $(CCGLAGS) -c shape.cpp

source.o: source.cpp shape.h
	g++ $(CCFLAGS) -c source.cpp

# Pseudo-target to remove object code and executable files

clean:
	rm *.o 
	rm assign9
