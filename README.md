# poker_deck_dealer - Appian Interview Technical Chanllenge 2022
A C++ program that shuffles and deals poker cards.
# Contents of the code folder:
## poker.cpp:
- Comprised of 
  -  Four classes: node, doublyLinkedList, stack & deck
  -  Function askForCard() that deals out a card after sorting a stack of cards in a deck object.
  -  main function() that orchestrates the execution of the poker program
## poker (Compiled Executable)
- This is simply a compiled executable of poker.cpp
- Was compiled using GNU's g++ compiler for .cpp files

# What the program does?
- Creates a deck of cards if requested and then deals up to 52 cards until the user requests for the program to stop executing. 

# How to compile and execute if you are new to g++?
## Executing poker executable
- [X] Simply navigate to the folder and type ./poker and it will execute

## Comile and execute a new executable built on poker.cpp
- [X] First: Ensure that GNU's g++ compiler is installed
- [X] Second: Type command g++ poker.cpp -o nameOfExecutable
- [X] Lastly: Type ./nameOfExecutable

- Example:
  - ~ % g++ poker.cpp -o poker
  - ~ % ./poker
