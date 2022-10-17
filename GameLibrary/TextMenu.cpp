#include "TextMenu.h"

#include <iostream>
#include <string>

using namespace std;

/*
    Greeting to user
    Display high score to user
    Display game options
*/
void TextMenu::drawMainMenu(int high_score)
{
    cout << "-------------- Hello! -----------------" << endl;

    if (high_score != -1)
    {
        cout << "Your high score is: " << high_score << endl;
    }

    cout << "Enter the 'P' key to begin playing" << endl;
    cout << "Enter the 'Q' key to quit" << endl;
    cout << "Enter the 'S' key to see previous game scores" << endl;
}

/*
    Implementation of reading in a key entered by user
    Convert keys entered by the user to lowercase
*/
string TextMenu::getMainMenuChoice()
{
    while (true)
    {
        string temp;
        getline(cin, temp);

        if (temp == "p" || temp == "P")
        {
            return "p";
        }
        else if (temp == "q" || temp == "Q")
        {
            return "q";
        }
        else if (temp == "s" || temp == "S")
        {
            return "s";
        }
        else
        {
            cout << "Please enter a valid input, either 'P', 'Q', or 'S'" << endl;
        }
    }
}

/*
    Display end menu key options
    Ask user to enter specific keys to play again or quit
*/
void TextMenu::drawEndMenu(int current_score, int high_score)
{
    cout << "------------ YOU DIED! ------------" << endl;
    cout << "Your score was: " << current_score << endl;

    if (current_score == high_score)
    {
        cout << "This is a new high score!" << endl;
    }

    if (high_score != -1 && high_score != current_score)
    {
        cout << "Your high score is: " << high_score << endl;
    }

    cout << "\nDo you want to play another game?" << endl;
    cout << "Enter 'P' to play again" << endl;
    cout << "Enter anything else to return to the main menu" << endl;
}

/*
    Record the key entered by the user
*/
string TextMenu::getEndMenuChoice()
{
    string temp;
    getline(cin, temp);

    if (temp == "p" || temp == "P")
    {
        return "p";
    }
    else
    {
        return "r";
    }
}

/*
    Display the previous game scores
*/
void TextMenu::drawLastScores(vector<int> last_scores)
{
    // Separator
    cout << endl;

    // Draw the previous game scores
    if (last_scores.empty())
    {
        cout << "There is no saved data" << endl;
        return;
    }
    cout << "Your last scores were:" << endl;

    // Print out the scores in the vector in reverse order (the most recent being at the top of the list)
    for (int i = (int)last_scores.size() - 1; i >= 0; i--)
    {
        cout << last_scores.size() - i << ": ";
        cout << last_scores[i] << endl;
    }

    // Separator
    cout << endl;
}

/*
    Wait for user input (for user to press the enter key)
*/
void TextMenu::waitForInput()
{
    // Wait for user
    cout << "Press enter to continue: " << endl;

    // Function expects a new line character (the enter key to be pressed) to return
    cin.get();
}