#include "TestMenu.h"

#include <iostream> 

int main(){

    // Create constructor of the class.
    TestMenu *test1 = new TestMenu;

    // Show main menu.
    test1 -> show_main_menu();

    return 0;
}