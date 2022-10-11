#include "TestMenu.h"
#include <cctype>

using namespace std;

// Implementation of drawing the menu.
void TextMenu::draw_main_menu(int high_score){
    cout << "Hello!" << endl;
    cout << "Your high score is " << high_score << endl;

    cout << "Press 'p' to play: " << endl;
    cin >> tolower(choice);

    // Use a switch statement
    switch(choice){
        case 'p':


        default:
    }
}
