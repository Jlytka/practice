#include <iostream>


using namespace std;
class Box {
    private:
    double a;
    double b;
    double c;
public:
    Box(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0)
          throw "some numbers are smaller than or equal to 0";

        cout << "the volume of box: " << a << " x " << b << " x " << c << " = " << vol() << endl;
    }
    double vol(){
    double v = a* b* c;
    return v;
    }

};