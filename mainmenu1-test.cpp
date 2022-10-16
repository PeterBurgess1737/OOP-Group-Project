#include "GameLibrary/TextMenu.h"

#include <iostream>

using namespace std;

int main() {
    // Create an object of the class
    TextMenu menu;

    menu.draw_main_menu(56);
    cout << menu.get_main_menu_choice() << endl;

    menu.draw_end_menu(56, 72);
    cout << menu.get_end_menu_choice() << endl;

    return 0;
}
