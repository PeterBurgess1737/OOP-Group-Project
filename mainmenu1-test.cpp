#include "TestMenu.h"

#include <iostream>

using namespace std;

int main() {

    // Create an object of the class
    TestMenu *menu = new TestMenu;

    // Test draw main menu with high score being 56
    menu->draw_main_menu(56);
    cout << menu->get_main_menu_choice() << endl;

    // Test draw end menu with current score being 56 
    menu->draw_end_menu(56, 78);
    cout << menu->get_end_menu_choice() << endl;

    return 0;
}