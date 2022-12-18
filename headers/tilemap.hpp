#ifndef tilemap_hpp
#define tilemap_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "asset.hpp"
#include "player.hpp"
#include "tile.hpp"
#include "tile_data.hpp"

using namespace std;
using namespace sf;

class Tilemap {
 private:
  Asset *asset;
  Texture *texture;
  TileData *tileData;
  Sprite spriteTile{};

  bool canMoveVertical(Player &player, View &view, bool isUp);
  bool canMoveHorizontal(Player &player, View &view, bool isRight);

 public:
  void init(TileData *tileData, Asset *asset);
  bool canMoveUp(Player &player, View &view);
  bool canMoveDown(Player &player, View &view);
  bool canMoveRight(Player &player, View &view);
  bool canMoveLeft(Player &player, View &view);
  void draw(RenderWindow &window);
};

#endif