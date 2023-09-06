#include <iostream>
#include "nota.h";
using namespace std;

template <class T>

class Zvuk : public Nota<T> {
private:
    T frequency;

public:
    Zvuk(const string& name, T octave, T duration, T frequency)
        : Nota<T>(name, octave, duration), frequency(frequency) {}

    void output() const override {
        cout << "sound: " << this->name << ", octave: " << this->octave
            << ", duration: " << this->duration << ", frequency: " << frequency << endl;
    }
};

template <class T>

class Zobrazhennya : public Nota<T> {
private:
    T x;
    T y;

public:
    Zobrazhennya(const string& name, T octave, T duration, T x, T y)
        : Nota<T>(name, octave, duration), x(x), y(y) {}

    void output() const override {
        cout << "pictures: " << this->name << ", octave: " << this->octave
            << ", duration: " << this->duration << ", coordinates: (" << x << ", " << y << ")" << endl;
    }
};