#include <iostream>

using namespace std;

template <typename T>

class Nota {
protected:
    T* data;
    string name;
    T octave;
    T duration;
    const int size = 4;
public:
    Nota(const string& name, T octave, T duration)
        : name(name), octave(octave), duration(duration) {}

    virtual void output() const = 0;
};






