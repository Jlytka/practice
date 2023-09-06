#ifndef DAT
#define DAT
#include<iostream>
#include "mam1.h"
#include "dauther1.h"
using namespace std;

class Dauther2 : private Dauther1 {
private:
    int amountOfZaza;
public:
    Dauther2(const string& name): Dauther1(name) {}

    int getAmountOfZaza() const{
        return amountOfZaza;
    }

    void torh();

    
    void input(){
        Mam1::input();
        
    }
    void zazaInfo();

    void output() const {
        Mam1::output();

    }

    void speak() const override {
        cout << "I am an artist" << endl;
    }
};
void Dauther2::zazaInfo(){
    cout << "how much zaza do you have? ";
    cin >> amountOfZaza;
}
void Dauther2:: torh(){
    if (amountOfZaza >= 1)
        cout << "you're lucky" << endl;
    else
        cout <<  "no." << endl;
}

#endif