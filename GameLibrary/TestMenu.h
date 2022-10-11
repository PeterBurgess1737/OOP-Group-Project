#ifndef OOP_GROUP_PROJECT_TESTMENU_H
#define OOP_GROUP_PROJECT_TESTMENU_H


#include <iostream>

using namespace std;

class TextMenu{
protected:
    char choice;
    int high_score;
    int current_score;

public:

    void draw_main_menu(int high_score);

    // when you die
    // close the game
    // You die, high score is " "
    // do you wish to play again? yes/no

    void draw_end_menu(int current_score);

    // press play
    // quit the game

};
#endif //OOP_GROUP_PROJECT_TESTMENU_H
