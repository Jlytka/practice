#ifndef DOT
#define DOT
#include <iostream>
#include "bioobj1.h"
#include "bioobj2.h"
using namespace std;

class bioobj3 : public bioobj1, private bioobj2 {
private:
    int moneyStatus;
public:
    Dauther1(const string& name): Bioobj1
(name), bioobj2("") {}

    void setMoney(int money){
        moneyStatus = money;
    }

    bool GetMoney(){
        return (moneyStatus > 1);
    }

    void IfWorking();

    void speak() const override {
        cout << "I love money" << endl;
    } 
    
};
void Dauther1:: IfWorking(){
    if (GetMoney())
        cout << "making money" << endl;
    else
        cout << "sleeping" << endl;
}

#endif