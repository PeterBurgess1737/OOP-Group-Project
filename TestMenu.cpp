#include "TestMenu.h"

#include <iostream>

using namespace std;

//char TestMenu::choice() { return key; }

void TestMenu::choice(int _key) { key = _key; }

void TestMenu::show_main_menu() {
  cout << "----------- Hello! -----------" << endl;
  cout << "Your high score is: " << high_score << endl;

  cout << "Press any key to begin playing: " << endl;
  choice(cin.get());
  getchar();
}