
# PROGRAM:    assign2
# PROGRAMMER: William Freriks
# LOGON ID:   z1698749
# DATE DUE:   2/12/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign3: source.o verifier.o 
	g++ $(CCFLAGS) -o assign3 source.o verifier.o 

# Rules to compile source code files to object code
source.o: source.cpp verifier.h
	g++ $(CCFLAGS) -c source.cpp

verifier.o: verifier.cpp verifier.h
	g++ $(CCFLAGS) -c verifier.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3



