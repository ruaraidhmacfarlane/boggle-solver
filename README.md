# boggle-solver
Three different methods for solving boggle games.

## Description

There is 3 different boggle solvers:

1) Simple Boggle Solver: Loops through the wordlist to find the word entered by user and returns YES/NO depending if its on the board.

2) Binary Search Boggle Solver: Similar to the Simple Boggle Solver, this method generates all possible words on the boggle board and uses a binary search to check if they are in the dictionary.

3) Efficient Boggle Solver: This solver takes longer to initialise but can search words much quicker, it builds a trie of all words on the boggle board so they can easily be found in the dictionary.

## Compiling & Running

run make
run ./boggle arg (arg is 1,2,3 depending on what boggle solver you wish to run)
