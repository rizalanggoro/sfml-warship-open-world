#ifndef player_hpp
#define player_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "direction.hpp"
#include "player_state.hpp"

using namespace sf;
using namespace std;

class Player {
 private:
  float textureFrameSize = 64;
  float frameSize = 32;

  vector<Texture> vectorFrontIdleFrame;
  vector<Texture> vectorFrontWalkFrame;
  vector<Texture> vectorBackIdleFrame;
  vector<Texture> vectorBackWalkFrame;
  vector<Texture> vectorLeftIdleFrame;
  vector<Texture> vectorLeftWalkFrame;
  vector<Texture> vectorRightIdleFrame;
  vector<Texture> vectorRightWalkFrame;

  Direction direction;
  PlayerState playerState = front_idle;

  Sprite sprite{};
  float velocity = 2;

  int frameCount = 30;
  Clock clockFrame;
  float intervalFrame;
  float delayFrame = 300;
  int currentFrameIndex = 0;

  void loadTexture();

 public:
  Player();
  Sprite* getSprite();
  float getVelocity();
  float getFrameSize();

  void setPlayerState(PlayerState playerState);
  void draw(RenderWindow& window);
};

#endif