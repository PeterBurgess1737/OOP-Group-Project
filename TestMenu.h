#ifndef TESTMENU_H
#define TESTMENU_H

#include <iostream>

using namespace std;

class TestMenu {
 protected:
  // int high_score;
  char key;
  int high_score; 

 public:
  // char choice();
  void choice(int _key);
  void show_main_menu();

  // Function that when you die, closes the game and displays a message
  // displaying that the player has died and their time spent in the game. The
  // user will be asked if they want to play the game again.
  void draw_end_menu(int current_score);
};
#endif