// Created by Savi Singh //

#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>
#include <ctime>
#include "HangMan.h"
using namespace std;

struct userName // database for leaderboard
{
    string names;
    double times;
};

bool Comparator(userName A, userName B) 
{
    return (A.times < B.times);
}

int main()
{
    ifstream file("words.txt"); 
    string s;
    vector <string> word;
    vector <string> hint;
    
    while(getline(file, s, ',')) {
        word.push_back(s); 
        getline(file, s);
        hint.push_back(s); 
    }
    
    cout << "-------------------------------------------\n";
    cout << "Welcome to HangMan! You will have 5 attempts to solve the mystery word." << endl;
    cout << "Type your name: ";
    string name;
    cin >> name;
    // cout << "Press enter to begin the game: ";
    // cin.ignore();
    cout << "Hello " << name;

    srand(time(NULL));
    int random_index = rand() % word.size(); // chooses a random word for the game

    HangMan g;
    cout << ", your job is to fill in the rest of these blanks!" << endl;
    g.setWord(word[random_index], hint[random_index]);
    file.close();

    auto start = chrono::steady_clock::now();
    g.choices(); // this is the funtion call that runs the entire game
    auto stop =  chrono::steady_clock::now();
    auto time_elapsed = chrono::duration_cast<chrono::seconds> (stop - start).count();
    double time = time_elapsed;

    int decider = g.getWinner();
    if(decider == 1) {
        g.leaderboardTimes(name, time);

        ifstream leaderboard("leaderboard.txt");
        fstream output("leaderboardfinal.txt");
        vector <userName> vec;
        string b; string names; double times;

        // This resorts the winners in correct order of time, from least to greatest in seconds
        while(getline(leaderboard, b)) {
            istringstream is(b);
            is >> names >> times;
            vec.push_back(userName({names, times}));
        }

        sort(vec.begin(), vec.end(), Comparator);
        for(int i = 0; i < vec.size(); i++) {
            output << vec[i].names << "," << vec[i].times << endl;
        }

        leaderboard.close();    
        output.close();
    }

    return 0;
}