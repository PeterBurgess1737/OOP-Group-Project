#include "TestMenu.h"

#include <iostream>

using namespace std;

int main() {
    // Create an object of the class

    TestMenu *menu = new TestMenu;

    menu->draw_main_menu(56);
    cout << menu->get_main_menu_choice() << endl;

    menu->draw_end_menu(56);
    cout << menu->get_end_menu_choice() << endl;

    return 0;
}