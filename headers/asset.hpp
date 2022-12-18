#ifndef asset_hpp
#define asset_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Asset {
 private:
  vector<Texture> vectorTiles;
  vector<Texture> vectorObjects;

  void loadTiles() {
    for (int a = 1; a <= 143; a++) {
      string path = "assets/images/tiles/Map_tile_" + to_string(a) + ".png";
      Texture texture{};
      if (texture.loadFromFile(path)) cout << path << " -> loaded!" << endl;
      this->vectorTiles.push_back(texture);
    }
  }

  void loadObjects() {
    for (int a = 0; a < 9; a++) {
      string path =
          "assets/images/objects/object-" + to_string(145 + a) + ".png";
      Texture texture{};
      if (texture.loadFromFile(path)) cout << path << " -> loaded!" << endl;
      this->vectorObjects.push_back(texture);
    }
  }

 public:
  Asset() {
    this->loadTiles();
    this->loadObjects();
  }

  vector<Texture> *getVectorTiles() { return &this->vectorTiles; }
  vector<Texture> *getVectorObjects() { return &this->vectorObjects; }
};

#endif