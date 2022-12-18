#include "../headers/state_world.hpp"

StateWorld::StateWorld(RenderWindow *window, string *route, Asset *asset) {
  this->window = window;
  this->route = route;
  this->asset = asset;

  this->tilemap.init(&this->tileData, this->asset);

  auto tileSize = this->tileData.getTileSize();
  auto tileCountW = this->tileData.getWidth();
  auto tileCountH = this->tileData.getHeight();

  // init view
  this->view = this->window->getDefaultView();
  this->view.setCenter(0, 0);
  this->view.move((tileCountW * tileSize) / 2, (tileCountH * tileSize) / 2);
  this->view.zoom(.5);
}

void StateWorld::run() {
  this->window->setView(this->view);
  this->tilemap.draw(*this->window);

  // init player position to center of window
  auto winCenter = this->window->getView().getCenter();
  auto playerSize = this->player.getFrameSize();

  CircleShape circleWarPoint{};
  circleWarPoint.setRadius(16);
  circleWarPoint.setFillColor(Color::Transparent);
  circleWarPoint.setOutlineColor(Color::Red);
  circleWarPoint.setOutlineThickness(1.32);
  circleWarPoint.setPosition(32 * 22, 32 * (50 - 15));
  this->window->draw(circleWarPoint);

  this->player.getSprite()->setPosition(winCenter.x, winCenter.y);
  this->player.getSprite()->setOrigin(playerSize, playerSize);
  this->player.draw(*this->window);

  if (this->player.getSprite()->getGlobalBounds().contains(
          circleWarPoint.getPosition().x + 16,
          circleWarPoint.getPosition().y + 16))
    this->isInWarPoint = true;
  else
    this->isInWarPoint = false;

  this->handleKeyboard();
}

void StateWorld::handleEvent(Event &event) {
  if (event.type == Event::Resized) {
    auto size = event.size;
    this->view.setSize(size.width, size.height);
    this->view.zoom(.5);
    this->zoomInCount = 3;
    this->zoomOutCount = 0;
  } else if (event.type == Event::KeyReleased) {
    auto code = event.key.code;
    if (this->isInWarPoint && code == Keyboard::Enter) {
      *this->route = "main_menu";
      this->window->setView(this->window->getDefaultView());
      this->view.move(0, -32);
    }
    if (code == Keyboard::Up) this->player.setPlayerState(back_idle);
    if (code == Keyboard::Down) this->player.setPlayerState(front_idle);
    if (code == Keyboard::Right) this->player.setPlayerState(right_idle);
    if (code == Keyboard::Left) this->player.setPlayerState(left_idle);
    if (code == Keyboard::Equal) {
      // zoom in
      if (this->zoomInCount > 0) {
        this->view.zoom(.9);
        this->zoomInCount--;
        this->zoomOutCount++;
      }
    }
    if (code == Keyboard::Dash) {
      // zoom out
      if (this->zoomOutCount > 0) {
        this->view.zoom(1.1);
        this->zoomInCount++;
        this->zoomOutCount--;
      }
    }
  }
}

void StateWorld::handleKeyboard() {
  // handle diagonal move
  if (Keyboard::isKeyPressed(Keyboard::Up) &&
      Keyboard::isKeyPressed(Keyboard::Right)) {
    // up right
    auto speed = this->player.getVelocity();
    auto sqrtSpeed = speed / 2 * sqrt(2);
    if (this->tilemap.canMoveUp(this->player, this->view) &&
        this->tilemap.canMoveRight(this->player, this->view)) {
      this->player.setPlayerState(right_walk);
      this->view.move(sqrtSpeed, -sqrtSpeed);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Up) &&
           Keyboard::isKeyPressed(Keyboard::Left)) {
    // up left
    auto speed = this->player.getVelocity();
    auto sqrtSpeed = speed / 2 * sqrt(2);
    if (this->tilemap.canMoveUp(this->player, this->view) &&
        this->tilemap.canMoveLeft(this->player, this->view)) {
      this->player.setPlayerState(left_walk);
      this->view.move(-sqrtSpeed, -sqrtSpeed);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Down) &&
           Keyboard::isKeyPressed(Keyboard::Right)) {
    // down right
    auto speed = this->player.getVelocity();
    auto sqrtSpeed = speed / 2 * sqrt(2);
    if (this->tilemap.canMoveDown(this->player, this->view) &&
        this->tilemap.canMoveRight(this->player, this->view)) {
      this->player.setPlayerState(right_walk);
      this->view.move(sqrtSpeed, sqrtSpeed);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Down) &&
           Keyboard::isKeyPressed(Keyboard::Left)) {
    // down left
    auto speed = this->player.getVelocity();
    auto sqrtSpeed = speed / 2 * sqrt(2);
    if (this->tilemap.canMoveDown(this->player, this->view) &&
        this->tilemap.canMoveLeft(this->player, this->view)) {
      this->player.setPlayerState(left_walk);
      this->view.move(-sqrtSpeed, sqrtSpeed);
    }
  }

  // handle horizontal and vertical move
  else if (Keyboard::isKeyPressed(Keyboard::Up)) {
    if (this->tilemap.canMoveUp(this->player, this->view)) {
      this->player.setPlayerState(back_walk);
      this->view.move(0, -this->player.getVelocity());
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Down)) {
    if (this->tilemap.canMoveDown(this->player, this->view)) {
      this->player.setPlayerState(front_walk);
      this->view.move(0, this->player.getVelocity());
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Right)) {
    if (this->tilemap.canMoveRight(this->player, this->view)) {
      this->player.setPlayerState(right_walk);
      this->view.move(this->player.getVelocity(), 0);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Left)) {
    if (this->tilemap.canMoveLeft(this->player, this->view)) {
      this->player.setPlayerState(left_walk);
      this->view.move(-this->player.getVelocity(), 0);
    }
  }
}