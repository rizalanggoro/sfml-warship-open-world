#include "../headers/tilemap.hpp"

void Tilemap::init(TileData *tileData, Asset *asset) {
  this->tileData = tileData;
  this->asset = asset;
}

void Tilemap::draw(RenderWindow &window) {
  int w = this->tileData->getWidth();
  int h = this->tileData->getHeight();
  double tileSize = this->tileData->getTileSize();

  int index = 0;
  for (int a = 0; a < h; a++) {
    for (int b = 0; b < w; b++) {
      auto tile1 = this->tileData->getTileLayer1()->at(index);
      auto tile2 = this->tileData->getTileLayer2()->at(index);

      // layer 1
      if (tile1.getType() != 0) {
        this->spriteTile.setTexture(
            this->asset->getVectorTiles()->at(tile1.getType() - 1));
        this->spriteTile.setPosition(tileSize * b, tileSize * a);

        window.draw(this->spriteTile);

        // RectangleShape rect{};
        // rect.setSize(Vector2f(32, 32));
        // rect.setOutlineColor(Color::Black);
        // rect.setOutlineThickness(1);
        // rect.setPosition(tileSize * b, tileSize * a);
        // rect.setFillColor(Color::Transparent);
        // window.draw(rect);
      }

      // layer 2
      if (tile2.getType() != 0) {
        this->spriteTile.setTexture(
            this->asset->getVectorTiles()->at(tile2.getType() - 1));
        this->spriteTile.setPosition(tileSize * b, tileSize * a);

        window.draw(this->spriteTile);
      }

      index++;
    }
  }
}

bool Tilemap::canMoveVertical(Player &player, View &view, bool isUp) {
  auto globalBounds = player.getSprite()->getGlobalBounds();
  int h = globalBounds.height;

  int tileSize = this->tileData->getTileSize();
  auto pos = player.getSprite()->getPosition();

  int col = pos.x / tileSize;
  int row = 0;
  if (isUp)
    row = (pos.y - player.getVelocity()) / tileSize;
  else
    row = (pos.y + h + player.getVelocity()) / tileSize;

  int index = col + row * this->tileData->getWidth();
  auto tileItem = this->tileData->getTileLayer1()->at(index);
  auto tileItem2 = this->tileData->getTileLayer2()->at(index);

  if (tileItem2.isAccessable())
    return true;
  else
    return tileItem.isAccessable();
}

bool Tilemap::canMoveHorizontal(Player &player, View &view, bool isRight) {
  auto globalBounds = player.getSprite()->getGlobalBounds();
  int w = globalBounds.width;

  int tileSize = this->tileData->getTileSize();
  auto pos = player.getSprite()->getPosition();

  int col = 0;
  if (isRight)
    col = (pos.x + player.getVelocity() + 8) / tileSize;
  else
    col = (pos.x - player.getVelocity() - 8) / tileSize;
  int row = pos.y / 32;

  int index = col + row * this->tileData->getWidth();
  auto tileItem = this->tileData->getTileLayer1()->at(index);
  auto tileItem2 = this->tileData->getTileLayer2()->at(index);

  if (tileItem2.isAccessable())
    return true;
  else
    return tileItem.isAccessable() && tileItem.isAccessableFromSide();
}

bool Tilemap::canMoveUp(Player &player, View &view) {
  return this->canMoveVertical(player, view, true);
}

bool Tilemap::canMoveDown(Player &player, View &view) {
  return this->canMoveVertical(player, view, false);
}

bool Tilemap::canMoveRight(Player &player, View &view) {
  return this->canMoveHorizontal(player, view, true);
}

bool Tilemap::canMoveLeft(Player &player, View &view) {
  return this->canMoveHorizontal(player, view, false);
}