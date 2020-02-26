#
# PROGRAM:    Application 9
# PROGRAMMER: William Freriks
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment9.exe: assignment9.o
	g++ $(CCFLAGS) -o assignment9.exe assignment9.o

# Rules to compile source code files to object code
assignment9.o: assignment9.cc assignment9.h
	g++ $(CCFLAGS) -c assignment9.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment9.exe

