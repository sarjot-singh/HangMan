// Created by Savi Singh //

#include <iostream>
#include <vector>
using namespace std;

class HangMan
{
    public:
    HangMan();
    void choices();
    void setWord(string word, string hint);
    void guessChar();
    void guessWord();
    void setInput(int input);
    void attemptsTracker();
    void hangmanDrawing();
    int getWinner();
    void leaderboardTimes(string named, double timed);

    private:
    string word;
    string hint;
    string named;
    double timed;
    vector<string> underscore;
    int input;
    int counter = 5;
    int winner = 0;
};
