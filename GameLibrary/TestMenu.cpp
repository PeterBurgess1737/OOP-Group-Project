#include "TestMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

char TestMenu::choice() { return key; }

void TestMenu::choice(int _key) { key = _key; }

void TestMenu::show_main_menu() {
  cout << "-------------- Hello! -----------------" << endl;
  cout << "Your high score is: " << high_score << endl;

  // Press 'P' to begin playing, or 'Q' to quit. 
  cout << "Press the 'P' key to begin playing, or 'Q' to quit: " << endl;
  // Keep reading in keys entered by the user 
  choice(cin.get());
  // Records the key pressed by the user 
  key_pressed = getchar();

  switch(key_pressed){
      case 'P':
      // Open the game window

      case 'Q':
      // Close the window

      default:
      // Remain on screen 

  }
}

void TestMenu::draw_end_menu(int current_score){
    cout << "------------ YOU DIED! ------------" << endl;
    cout << "Your score was: " << current_score << endl;

    // Press 'M' to return to the main menu and 'Q' to quit. Use a switch statement. 
      cout << "Press the 'M' key to return to the main menu, or 'Q' to quit" << endl;
        choice(cin.get());
        key_pressed = getchar();

  switch(key_pressed){
      case 'M':
      // Return to the main menu

      case 'Q':
      // Close the window 

      default:
      // Remain on screen 

  }
}
