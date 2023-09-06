#include <iostream>
#include <string>

class box {
public:
  box(double length, double width, double height) : length_(length), width_(width), height_(height) {
    if (length_ <= 0 || width_ <= 0 || height_ <= 0)
      throw "Some numbers are smaller than 0";

    std::cout << "Box created with dimensions " << length_ << " x " << width_ << " x " << height_ << "and v = " << vol() << std::endl;
  }
  double vol(){
    double v = length_* width_* height_;
    return v;
  }
private:
  double length_;
  double width_;
  double height_;
};

int main() {
  double length, width, height;

  std::cout << "Enter length, width and height: ";
  if (!(std::cin >> length >> width >> height)) {
    std::cerr << "Error: Invalid input" << std::endl;
    exit(1);
  }

  try {
    box boxx(length, width, height);
  } catch(const char* error_msg) {
    std::cerr << "Error: " << error_msg << std::endl;
    exit(1);
  }

  return 0;
}
