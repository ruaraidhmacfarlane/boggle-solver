EXENAME = boggle
OBJS = main.o player.o board.o dice.o dictionary.o node.o trie.o

CXX = g++
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -std=c++1y 

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp dice.h board.h player.h board_dimensions.h
	$(CXX) $(CXXFLAGS) main.cpp

board.o : board.cpp board.h dice.h board_dimensions.h
	$(CXX) $(CXXFLAGS) board.cpp

dice.o : dice.cpp dice.h
	$(CXX) $(CXXFLAGS) dice.cpp

player.o : player.cpp player.h dictionary.h trie.h board_dimensions.h
	$(CXX) $(CXXFLAGS) player.cpp

dictionary.o : dictionary.cpp dictionary.h
	$(CXX) $(CXXFLAGS) dictionary.cpp

trie.o : trie.cpp trie.h node.h
	$(CXX) $(CXXFLAGS) trie.cpp

node.o : node.cpp node.h
	$(CXX) $(CXXFLAGS) node.cpp

clean :
	-rm -f *.o $(EXENAME)