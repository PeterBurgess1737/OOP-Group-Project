#ifndef TEXTMENU_H
#define TEXTMENU_H

#include <string>
#include <vector>

using namespace std;

class TextMenu{
public:
    // Function to draw main menu and see available options
    void drawMainMenu(int high_score);

    // Function to get main menu choice from user
    string getMainMenuChoice();

    // Function to draw end menu and see available options
    void drawEndMenu(int current_score, int high_score);

    // Function to get end menu choice from user
    string getEndMenuChoice();

    // Display the previous scores
    void drawLastScores(vector<int> last_scores);

    // Wait for input
    void waitForInput();
};
#endif