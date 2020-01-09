#
# PROGRAM:    assign3
# PROGRAMMER: Cory Stojan
# LOGON ID:   z1804761
# DATE DUE:   27FEB18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign3: assign3.o verifier.o
	g++ $(CCFLAGS) -o assign3 assign3.o verifier.o

# Rules to compile source code files to object code
assign3.o: assign3.cpp verifier.h
	g++ $(CCFLAGS) -c assign3.cpp

verifer.o: verifier.cpp
	g++ $(CCFLAGS) -c verifier.cpp

verifier.h:
	
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3
