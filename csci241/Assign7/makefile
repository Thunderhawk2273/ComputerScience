
# PROGRAM:    Application 7
# PROGRAMMER: William Freriks

# Compiler variables
CCFLAGS = -ansi -Wall -ggdb

# Rule to link object code files to create executable file
assign7: source.o
	g++ $(CCFLAGS) -o assign7 source.o

# Rules to compile source code files to object code
source.o: source.cpp
	g++ $(CCFLAGS) -c source.cpp


# Pseudo-target to remove object code and executable files

clean:
	rm *.o assign7
