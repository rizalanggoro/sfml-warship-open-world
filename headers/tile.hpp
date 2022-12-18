#ifndef tile_hpp
#define tile_hpp

class Tile {
 private:
  int type;
  bool accessable;
  bool accessableFromSide = true;

 public:
  void setType(int type) { this->type = type; }
  int getType() { return this->type; }

  void setAccessable(bool accessable) { this->accessable = accessable; }
  void setAccessableFromSide(bool accessable) {
    this->accessableFromSide = accessable;
  }

  bool isAccessable() { return this->accessable; }
  bool isAccessableFromSide() { return this->accessableFromSide; }
};

#endif