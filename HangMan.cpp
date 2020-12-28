// Created by Savi Singh //

#include <iostream>
#include <fstream>
#include <sstream>
#include "HangMan.h"
using namespace std;

HangMan::HangMan() {}

void HangMan::choices() // Player choices
{
    do{
        cout << "-------------------------------------------\n";
        cout << "Attempts remaining: " << counter << endl;
        cout << "1. Guess a letter" << endl;
        cout << "2. Guess the entire word" << endl;
        cout << "3. View the hint" << endl;
        cout << "CHOICE: ";
        cin >> input;
        setInput(input);
        cout << "-------------------------------------------" << endl;

        switch(input)
        {
        case 1: guessChar();
            break;
        case 2: guessWord();
            break;
        case 3: cout << "Hint: " << hint << endl;
            break;
        case 4: break;
        default:
            cout << "Enter valid choice!" << endl;
            break;
        }
    }while(input!=4);
}

void HangMan::setWord(string word, string hint) // Creates underscores of the chosen random word
{
    this->word = word;
    this->hint = hint;

    for(int i = 0; i < word.size(); i++) {
        underscore.push_back("_");
    }
    for(int i = 0; i < word.size(); i++) {
        cout << underscore[i] << " ";
    }
    cout << endl;
}

void HangMan::guessChar() // Guessing a character of the word
{
    string guess;
    cout << "Enter a character: ";
    cin >> guess;

    for(int i = 0; i <= word.length(); i++) { 
        if(word.substr(i, guess.length()) == guess) { 
            underscore[i] = guess;
            bool runOnce= true; // from a stack overflow discussion
            if(runOnce) {
                cout << "Your guess was correct!" << endl;
                runOnce = false;
            }
        }
    }

    for(int i = 0; i < word.size(); i++) {
        cout << underscore[i] << " ";
    }
    cout << endl;
    attemptsTracker();
}

void HangMan::guessWord() // Guessing the entire word
{
    string guess;
    cout << "Enter a word: ";
    cin >> guess;

    if(word == guess) { 
        cout << "-------------------------------------------\n";
        cout << "Congrats you got the answer!" << endl;
        cout << "-------------------------------------------\n";
        input = 4;
        winner = 1;
    } else {
        cout << "Wrong answer!" << endl;
        for(int i = 0; i < word.size(); i++) {
            cout << underscore[i] << " ";
        }
        cout << endl;
        attemptsTracker();
    }
}

void HangMan::setInput(int input) // Relates back to the choices menu
{
    this->input = input;
}

void HangMan::attemptsTracker() // Counts player attempts
{
    counter--;
    hangmanDrawing();
    if(counter == 0) {
        cout << "-------------------------------------------\n";
        cout << "You ran out of attempts! Game Over..." << endl;
        cout << "-------------------------------------------\n";
        input = 4;
    }
}

void HangMan::hangmanDrawing()
{
    if(counter == 4) {
        cout << " |  " << endl;
        cout << " O  " << endl;
    }
    if(counter == 3) {
        cout << " |  " << endl;
        cout << " O  " << endl;
        cout << "/|  " << endl;
    }
    if(counter == 2) {
        cout << " |  " << endl;
        cout << " O  " << endl;
        cout << "/|\\" << endl;
    }
    if(counter == 1) {
        cout << " |  " << endl;
        cout << " O  " << endl;
        cout << "/|\\" << endl;
        cout << "/   " << endl;
    }
    if(counter == 0) {
        cout << " |  " << endl;
        cout << " O  " << endl;
        cout << "/|\\" << endl;
        cout << "/ \\" << endl;
    }
}

int HangMan::getWinner() // If player succeeds
{
    return winner;
}

void HangMan::leaderboardTimes(string named, double timed) // Places the winners in a text file
{
    fstream out_file("leaderboard.txt", ios::out | ios::app);
    out_file << named << " " << timed << endl;
    out_file.close();
}