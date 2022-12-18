#ifndef state_main_menu_hpp
#define state_main_menu_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "typeface.hpp"

using namespace std;
using namespace sf;

class StateMainMenu {
 private:
  RenderWindow *window;
  string *route;
  Typeface *typeface;
  vector<string> menus{"PLAY", "ABOUT", "HOW TO PLAY", "EXIT"};
  int selectedMenu = 0;

 public:
  StateMainMenu(RenderWindow *window, string *route, Typeface *typeface);
  void run();
  void handleEvent(Event &event);
};

#endif