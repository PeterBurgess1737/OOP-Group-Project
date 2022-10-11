#include "TestMenu.h"
#include <cctype>

using namespace std;

// Implementation of drawing the menu.
void TextMenu::draw_main_menu(int high_score){
    cout << "Hello!" << endl;
    cout << "Your high score is " << frame_counter << endl;

    cout << "Press the 'p' key to play the game: " << endl;
    cin >> tolower(choice);

    // Use a switch statement
    switch(choice){
        case 'p':


        default:
    }
}
