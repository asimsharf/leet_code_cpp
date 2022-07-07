CPP = g++ --std=c++20  -o executable
RMs	=	rm -f

all:
	$(RMs) *.out && $(CPP) main.cpp 

run: 
	executable
