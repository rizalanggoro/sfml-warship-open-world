#include "../headers/player.hpp"

Player::Player() {
  this->loadTexture();

  this->intervalFrame = this->clockFrame.getElapsedTime().asMilliseconds();
}

void Player::loadTexture() {
  string idlePaths[] = {
      "assets/images/players/citizen/back/Idle/0_Citizen_Idle_0",
      "assets/images/players/citizen/front/Idle/0_Citizen_Idle_0",
      "assets/images/players/citizen/left/Idle/0_Citizen_Idle_0",
      "assets/images/players/citizen/right/Idle/0_Citizen_Idle_0",
  };
  string walkPaths[] = {
      "assets/images/players/citizen/back/Walk/0_Citizen_Walk_0",
      "assets/images/players/citizen/front/Walk/0_Citizen_Walk_0",
      "assets/images/players/citizen/left/Walk/0_Citizen_Walk_0",
      "assets/images/players/citizen/right/Walk/0_Citizen_Walk_0",
  };

  for (int a = 0; a < 30; a++) {
    for (int b = 0; b < 4; b++) {
      Texture idle{}, walk{};

      string idleB = idlePaths[b] + (a < 10 ? "0" : "") + to_string(a) + ".png";
      string walkB = walkPaths[b] + (a < 10 ? "0" : "") + to_string(a) + ".png";

      idle.loadFromFile(idleB);
      walk.loadFromFile(walkB);

      idle.setSmooth(true);
      walk.setSmooth(true);

      if (b == 0) {
        this->vectorBackIdleFrame.push_back(idle);
        this->vectorBackWalkFrame.push_back(walk);
      } else if (b == 1) {
        this->vectorFrontIdleFrame.push_back(idle);
        this->vectorFrontWalkFrame.push_back(walk);
      } else if (b == 2) {
        this->vectorLeftIdleFrame.push_back(idle);
        this->vectorLeftWalkFrame.push_back(walk);
      } else if (b == 3) {
        this->vectorRightIdleFrame.push_back(idle);
        this->vectorRightWalkFrame.push_back(walk);
      }
    }
  }

  cout << "load done" << endl;

  auto spriteBounds = this->sprite.getGlobalBounds();
  this->sprite.setScale((this->frameSize / this->textureFrameSize),
                        (this->frameSize / this->textureFrameSize));
}

Sprite *Player::getSprite() { return &this->sprite; }

float Player::getVelocity() { return this->velocity; }

float Player::getFrameSize() { return this->frameSize; }

void Player::setPlayerState(PlayerState playerState) {
  this->playerState = playerState;
}

void Player::draw(RenderWindow &window) {
  if (this->intervalFrame >= this->delayFrame) {
    if (this->currentFrameIndex < this->frameCount - 1)
      this->currentFrameIndex++;
    else
      this->currentFrameIndex = 0;
  }

  vector<Texture> *vectorFramePtr = NULL;
  if (this->playerState == front_idle)
    vectorFramePtr = &this->vectorFrontIdleFrame;
  else if (this->playerState == front_walk)
    vectorFramePtr = &this->vectorFrontWalkFrame;

  else if (this->playerState == back_idle)
    vectorFramePtr = &this->vectorBackIdleFrame;
  else if (this->playerState == back_walk)
    vectorFramePtr = &this->vectorBackWalkFrame;

  else if (this->playerState == right_idle)
    vectorFramePtr = &this->vectorRightIdleFrame;
  else if (this->playerState == right_walk)
    vectorFramePtr = &this->vectorRightWalkFrame;

  else if (this->playerState == left_idle)
    vectorFramePtr = &this->vectorLeftIdleFrame;
  else if (this->playerState == left_walk)
    vectorFramePtr = &this->vectorLeftWalkFrame;

  this->sprite.setTexture(vectorFramePtr->at(this->currentFrameIndex));

  window.draw(this->sprite);

  // CircleShape circle{};
  // circle.setRadius(1);
  // circle.setFillColor(Color::Red);
  // auto pos = this->sprite.getPosition();
  // circle.setPosition(pos.x - 1, pos.y - 1);

  // window.draw(circle);
}
