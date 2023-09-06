#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Point {
protected:
    int x;
    int y;

public:
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    void print() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

class ColoredPoint : public Point {
private:
    string color;

public:
    ColoredPoint(int xCoord, int yCoord, const string& pointColor) : Point(xCoord, yCoord), color(pointColor) {}

    void print() const {
        cout << "Colored Point: (" << setw(2) << left << x << ", " << setw(2) << left << y << ") - Color: " << color << endl;
    }
};

int main() {
    Point p(333, 4455);
    ColoredPoint cp(8234324, 2343432, "light red");

    p.print();
    cp.print();

    return 0;
}
