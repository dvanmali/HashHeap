CXX=clang++ -Wall
OBJS = hashheap.cpp heap.cpp
LIST = README Makefile main.cpp heap.h heap.cpp hashheap.h hashheap.cpp sample.txt script.sh script_prof.sh prog1-testcases/*

all:
	g++ main.cpp $(OBJS) -o prog1
	@echo "	Use a command with syntax './prog1 < sample.txt' to test"
	@echo "	Test file format:"
	@echo "		First Line must be size of hashtable"
	@echo "		Second Line should be number of operations that follow"
	@echo "		Next few lines must be that many operations that follow"
	@echo "		Last Line should be print command"

turnin:
	turnin prog1@cs130a $(LIST)

clean:
	rm -f *~ prog1
