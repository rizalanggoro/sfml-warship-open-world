#ifndef state_world_hpp
#define state_world_hpp

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "asset.hpp"
#include "player.hpp"
#include "tile_data.hpp"
#include "tilemap.hpp"

using namespace sf;
using namespace std;

class StateWorld {
 private:
  // vector<Texture> vectorTiles{};
  Asset *asset;

  int zoomInCount = 3;
  int zoomOutCount = 0;
  TileData tileData{};
  Tilemap tilemap{};
  Player player{};
  View view{};
  RenderWindow *window;
  string *route;

  void handleKeyboard();

 public:
  StateWorld(RenderWindow *window, string *route, Asset *asset);
  void setAsset(Asset *asset);

  void run();
  void handleEvent(Event &event);
};

#endif