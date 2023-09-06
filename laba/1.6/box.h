#include <iostream>


class box {
  private:
  double length;
  double width;
  double height;
public:
  box(double l, double w, double h) : length(l), width(w), height(h) {
    if (length <= 0 || width <= 0 || height <= 0)
      throw "Some input is smaller than  0";

    
  }
  double vol(){
    double volume = length* width* height;
    return volume;
  }

};
