#include "TestMenu.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Greeting to user
    Display high score to user
    Display game options
*/
void TestMenu::draw_main_menu(int high_score) {
    cout << "-------------- Hello! -----------------" << endl;
    cout << "Your high score is: " << high_score << endl;

    cout << "Press the 'P' key to begin playing" << endl;
    cout << "Press the 'Q' key to quit" << endl;
    cout << "Press the 'S' key to see previous game scores" << endl;
}

/*
    Implementation of reading in a key entered by user
    Convert keys entered by the user to lowercase
*/

string TestMenu::get_main_menu_choice() {
    while (true) {
        string temp;
        cin >> temp;

        if (temp == "p" || temp == "P") {
            return "p";
        } else if(temp == "q" || temp == "Q"){
            return "q";
        } else if(temp == "s" || temp == "S"){
            return "s";
        }
        else {
            cout << "Please enter a valid input, either 'P', 'Q', or 'S'" << endl;
        }
    }
}

/*
    Display end menu key options
    Ask user to enter specific keys to play again or quit
*/
void TestMenu::draw_end_menu(int current_score, int high_score) {
    cout << "------------ YOU DIED! ------------" << endl;
    cout << "Your score was: " << current_score << endl;
    cout << "Your high score is: " << high_score << endl;

    cout << "Do you want to play another game?" << endl;
    cout << "Press 'P' to play again" << endl;
    cout << "Press any other key to quit" << endl;
}

/*
    Record the key pressed by the user
*/

string TestMenu::get_end_menu_choice() {
    string temp;
    cin >> temp;

    if (temp == "p" || temp == "P") {
        return "p";
    } else {
        return "Quit";
    }
}