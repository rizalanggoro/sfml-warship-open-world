#ifndef asset_hpp
#define asset_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Asset {
 private:
  vector<Texture> vectorTiles;

  void loadTiles() {
    for (int a = 1; a <= 143; a++) {
      string path = "assets/images/tiles/Map_tile_" + to_string(a) + ".png";
      Texture texture{};
      if (texture.loadFromFile(path)) cout << path << " -> loaded!" << endl;
      this->vectorTiles.push_back(texture);
    }
  }

 public:
  Asset() { this->loadTiles(); }

  vector<Texture> *getVectorTiles() { return &this->vectorTiles; }
};

#endif