#ifndef typeface_hpp
#define typeface_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Typeface {
 private:
  Font retroGaming{};

 public:
  Typeface() {
    this->retroGaming.loadFromFile("assets/fonts/Retro Gaming.ttf");
  }

  Font *getRetroGaming() { return &this->retroGaming; }
};

#endif