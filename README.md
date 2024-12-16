# HangMan

Unique code with structured organization that runs the entire game with one function call even with multiple files of code.

## Getting Started

### Game Basics

1. Two player game. Player 1 who thinks of the word and Player 2 the guesser
2. Game starts with a series of empty slots
3. On each turn, Player 2 guesses a letter. If the letter belongs to the word, Player 1 adds it to the corresponding position.
4. If Player 2 guesses a letter which does not belong to the word, Player 1 draws one component of the hangman diagram.
5. At any time during the game, Player 2 can guess the entire word (instead of just guessing a single character). If the guess is correct, the game is over.
6. The game is over when either Player 2 guesses the word (character by character or the entire word at once) or when the hangman diagram is completed.


### Note:
- The file "words.txt" can be modified and the program will randomly pick one word at the start of each game. Each word contains a hint.
- The file "leaderboardfinal" contains the time (in seconds) it took to guess a word for each player.

### Prerequisites

g++ compiler

### Installing

Begin by loading files into code editor of choice. An example of how to run on Visual Studio Code is given below.


1. Open HangManDriver.cpp with the other files in the same folder

2. To run the game, enter the command below
```
g++ HangManDriver.cpp HangMan.cpp -std=c++11
```

3. The instructions to play the game will be given if it runs successfully

## Authors

* **Savi Singh** - (https://github.com/saviss33)

## License

This project is licensed under the GNU GENERAL PUBLIC License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Instructors
