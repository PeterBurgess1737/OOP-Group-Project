#include "TestMenu.h"
#include <iostream>

using namespace std;

char TestMenu::choice() { return key; }

void TestMenu::choice(int _key) { key = _key; }

void TestMenu::show_main_menu() {
  cout << "----------- Hello! -----------" << endl;
  cout << "Your high score is: " << high_score << endl;

  // Press 'P' to begin playing, or 'Q' to quit. Use a switch statement 
  cout << "Press any key to begin playing: " << endl;
  choice(cin.get());
  getchar();
}

void TestMenu::draw_end_menu(int current_score){
    cout << "----------- YOU DIED! -----------" << endl;
    cout << "Your score was: " << current_score << endl;

    // Press 'M' to return to the main menu and 'Q' to key. Use a switch statement. 
      cout << "Press any key to begin playing: " << endl;
      choice(cin.get());
      getchar();
}