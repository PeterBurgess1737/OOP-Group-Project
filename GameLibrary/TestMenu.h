#ifndef TESTMENU_H
#define TESTMENU_H

#include <iostream>

using namespace std;

class TestMenu {

public:
    // Function to draw main menu and see available options
    void draw_main_menu(int high_score);

    // Function to get main menu choice from user
    string get_main_menu_choice();

    // Function to draw end menu and see available options
    void draw_end_menu(int current_score, int high_score);

    // Function to get end menu choice from user
    string get_end_menu_choice();


};
#endif