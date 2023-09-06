#include <iostream>
#include "box.h"
using namespace std;



int main() {
  double length, width, height;

  cout << "Enter length, width and height: ";
  if (!(cin >> length >> width >> height)) {
    cout << "Error: Invalid input" << endl;
    exit(1);
  }

  try {
    box boxx(length, width, height);
    cout << "creater shape with " << length << " x " << width << " x " << height << endl;
    cout << "Vol: " << boxx.vol() << endl;
  } catch(const char* charr) {
    cout << "Error: " << charr<< endl;
    exit(1);
  }
  return 0;
}
