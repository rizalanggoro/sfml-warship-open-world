#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "headers/asset.hpp"
#include "headers/state_main_menu.hpp"
#include "headers/state_world.hpp"
#include "headers/typeface.hpp"

#define DEBUG true

using namespace sf;
using namespace std;

string route = "main_menu";

int main() {
  RenderWindow window(VideoMode(1280, 720), "SFML | Starter V2");
  window.setFramerateLimit(60);

  Typeface typeface{};
  Asset asset{};

  // TileData tileData{};
  // auto tilemapWidth = tileData.getWidth();
  // auto tilemapHeight = tileData.getHeight();

  // Tilemap tilemap{};
  // tilemap.setTileData(&tileData);

  // View view = window.getDefaultView();
  // view.zoom(.5);
  // view.setCenter(0, 0);
  // view.move((tilemapWidth * 32) / 2, (tilemapHeight * 32) / 2);

  // Player player1{};

  // Texture texture{};
  // texture.loadFromFile("assets/images/players/citizen/0_Citizen_Idle_000.png");

  // Vector2f targetSize(32, 32);
  // Sprite sprite{};
  // sprite.setTexture(texture);

  // auto bounds = sprite.getGlobalBounds();
  // sprite.setScale(targetSize.x / bounds.width, targetSize.y / bounds.height);

  // sprite.setPosition((tilemapWidth * 32) / 2 - 32,
  //                    (tilemapHeight * 32) / 2 - 32);

  // CircleShape circle{};
  // circle.setFillColor(Color::Red);
  // circle.setRadius(16);
  // circle.setPosition((tilemapWidth * 32) / 2, (tilemapHeight * 32) / 2);

  // CircleShape circle2{};
  // circle2.setFillColor(Color::Blue);
  // circle2.setPosition((tilemapWidth * 32) / 2 - 16,
  //                     (tilemapHeight * 32) / 2 - 16);
  // circle2.setRadius(16);

  // float zoomValue = 1;

  StateWorld stateWorld{&window, &route, &asset};
  StateMainMenu stateMainMenu{&window, &route, &typeface};

  while (window.isOpen()) {
    Event event{};
    while (window.pollEvent(event)) {
      if (route == "main_menu") stateMainMenu.handleEvent(event);
      if (route == "world") stateWorld.handleEvent(event);

      if (event.type == Event::Closed) window.close();
    }
    //   if (event.type == Event::Closed) window.close();
    //   if (event.type == Event::KeyPressed) {
    //     auto code = event.key.code;
    //     if (code == Keyboard::Dash) {
    //       view.zoom(1.1);

    //       zoomValue += 1;
    //     }
    //     if (code == Keyboard::Equal) {
    //       view.zoom(0.9);
    //       zoomValue -= 1;
    //     }
    //     if (code == Keyboard::Escape) window.close();
    //   }
    //   if (event.type == Event::Resized) {
    //     view.setSize(event.size.width, event.size.height);
    //     view.zoom(.5);
    //   }

    //   if (event.type == Event::KeyReleased) {
    //     auto code = event.key.code;
    //     if (code == Keyboard::Up) player1.setPlayerState(back_idle);
    //     if (code == Keyboard::Down) player1.setPlayerState(front_idle);
    //     if (code == Keyboard::Right) player1.setPlayerState(right_idle);
    //     if (code == Keyboard::Left) player1.setPlayerState(left_idle);
    //   }
    // }

    // if (Keyboard::isKeyPressed(Keyboard::Up)) {
    //   if (tilemap.canMoveUp(player1, view)) {
    //     player1.setPlayerState(back_walk);
    //     view.move(0, -2);
    //   }
    // }
    // if (Keyboard::isKeyPressed(Keyboard::Down)) {
    //   if (tilemap.canMoveDown(player1, view)) {
    //     player1.setPlayerState(front_walk);
    //     view.move(0, 2);
    //   }
    // }
    // if (Keyboard::isKeyPressed(Keyboard::Right)) {
    //   if (tilemap.canMoveRight(player1, view)) {
    //     player1.setPlayerState(right_walk);
    //     view.move(2, 0);
    //   }
    // }
    // if (Keyboard::isKeyPressed(Keyboard::Left)) {
    //   if (tilemap.canMoveLeft(player1, view)) {
    //     player1.setPlayerState(left_walk);
    //     view.move(-2, 0);
    //   }
    // }

    // if (Keyboard::isKeyPressed(Keyboard::Up)) circle2.move(0, -5);
    // if (Keyboard::isKeyPressed(Keyboard::Down)) circle2.move(0, 5);
    // if (Keyboard::isKeyPressed(Keyboard::Right)) circle2.move(5, 0);
    // if (Keyboard::isKeyPressed(Keyboard::Left)) circle2.move(-5, 0);

    window.clear(Color::White);

    if (route == "world") {
      stateWorld.run();
    } else if (route == "main_menu")
      stateMainMenu.run();
    else {
      CircleShape circle{};
      circle.setFillColor(Color::Red);
      circle.setRadius(32);
      window.draw(circle);
    }

    // window.setView(view);

    // auto pos1 = circle.getPosition();
    // auto pos2 = circle2.getPosition();

    // auto enemyV = 3;

    // if (pos1.x != pos2.x && pos1.y != pos2.y) {
    //   auto offsetX = pos2.x - pos1.x;
    //   auto offsetY = pos2.y - pos1.y;

    //   if (offsetX < 0) offsetX *= -1;
    //   if (offsetY < 0) offsetY *= -1;

    //   if (offsetX < enemyV)
    //     circle.setPosition(pos2.x, pos1.y);
    //   else if (offsetY < enemyV)
    //     circle.setPosition(pos1.x, pos2.y);
    //   else
    //     circle.move(enemyV * sqrt(2) / 2 * (pos2.x > pos1.x ? 1 : -1),
    //                 enemyV * sqrt(2) / 2 * (pos2.y > pos1.y ? 1 : -1));

    // } else {
    //   if (pos1.x != pos2.x) {
    //     auto offset = pos2.x - pos1.x;
    //     if (offset < 0) offset *= -1;
    //     if (offset < enemyV)
    //       circle.setPosition(pos2.x, pos1.y);
    //     else
    //       circle.move(enemyV * (pos2.x > pos1.x ? 1 : -1), 0);
    //   }

    //   if (pos1.y != pos2.y) {
    //     auto offset = pos2.y - pos1.y;
    //     if (offset < 0) offset *= -1;
    //     if (offset < enemyV)
    //       circle.setPosition(pos1.x, pos2.y);
    //     else
    //       circle.move(0, enemyV * (pos2.y > pos1.y ? 1 : -1));
    //   }
    // }

    // if (pos1.y != pos2.y) {
    //   circle.move(0, 1 * (pos2.y > pos1.y ? 1 : -1));
    // }

    // window.draw(circle2);

    // if (GameState::state == game_state_world) {
    //   tilemap.draw(window);
    //   player1.getSprite()->setOrigin(32, 32);
    //   player1.setPosition(window.getView().getCenter().x,
    //                       window.getView().getCenter().y);
    //   player1.draw(window);
    // }

    // window.draw(circle);

    // window.draw(sprite);

    window.display();
  }

  return 0;
}