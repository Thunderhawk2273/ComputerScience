#
# PROGRAM:    assign2
# PROGRAMMER: William Freriks
# LOGON ID:   z1698749
# DATE DUE:   2/12/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rules to compile source code files to object code
assign1.o: assign1.cc
	g++ $(CCFLAGS) -c assign1.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1

