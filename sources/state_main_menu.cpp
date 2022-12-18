#include "../headers/state_main_menu.hpp"

StateMainMenu::StateMainMenu(RenderWindow *window, string *route,
                             Typeface *typeface) {
  this->window = window;
  this->route = route;
  this->typeface = typeface;
}

void StateMainMenu::run() {
  auto winCenter = this->window->getView().getCenter();
  auto space = 8;
  auto textSize = 24;

  Text title, text{};
  title.setString("Warship: Open World!");
  title.setFillColor(Color::Black);
  title.setStyle(Text::Bold);
  title.setCharacterSize(48);
  title.setFont(*this->typeface->getRetroGaming());

  auto titleWidth = title.getGlobalBounds().width;
  title.setPosition(winCenter.x - (titleWidth / 2), winCenter.y / 4);

  this->window->draw(title);

  for (int a = 0; a < this->menus.size(); a++) {
    text.setString(this->menus.at(a));
    text.setFont(*this->typeface->getRetroGaming());
    text.setFillColor(a == this->selectedMenu ? Color::Black
                                              : Color(0, 0, 0, 100));
    text.setCharacterSize(textSize);

    auto menuSize = this->menus.size();
    auto totalHeight = (textSize * menuSize) + (space * (menuSize - 1));
    auto width = text.getGlobalBounds().width;

    text.setPosition(
        winCenter.x - (width / 2),
        (winCenter.y - totalHeight / 2) + (a * textSize) + (a * space));

    this->window->draw(text);
  }
}

void StateMainMenu::handleEvent(Event &event) {
  if (event.type == Event::KeyPressed) {
    auto code = event.key.code;
    if (code == Keyboard::Up) {
      if (this->selectedMenu > 0) this->selectedMenu--;
    } else if (code == Keyboard::Down) {
      if (this->selectedMenu < (this->menus.size() - 1)) this->selectedMenu++;
    } else if (code == Keyboard::Enter) {
      switch (this->selectedMenu) {
        case 0:
          *this->route = "world";
          break;

        case 3:
          this->window->close();
          break;
      }
    }
  }
}