#include <iostream>

using namespace std;

class Drib {
    private:
        int numerator;
        int denominator;

    public:
        
        Drib(int n, int d) {
            numerator = n;
            denominator = d;
        }
        Drib operator+(Drib other) {
            int n = numerator * other.denominator + other.numerator * denominator;
            int d = denominator * other.denominator;
            return Drib(n, d);
        }

        Drib operator-(Drib  other) {
            int n = numerator * other.denominator - other.numerator * denominator;
            int d = denominator * other.denominator;
            return Drib(n, d);
        }



       friend Drib& operator--(Drib& p);

        friend ostream& operator<<(ostream& os, Drib r) {
            os << r.numerator << "/" << r.denominator;
            return os;
        }
        bool operator==(Drib other) {
            return numerator * other.denominator == denominator * other.numerator;
        }
        

        bool operator!=(Drib other) {
            return numerator * other.denominator != denominator * other.numerator;
        }
        

};


