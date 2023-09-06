#ifndef BOY
#define BOY
#include<iostream>
using namespace std;

class Boyfriend{
private:
    string name;

public:
    Boyfriend(const string& name): name(name) {}
    string workOnWho;
    
    void input();

    void output() const;
};
void Boyfriend:: input(){
    cout << "enter the name of the boss: ";
    cin >> workOnWho;
}
void Boyfriend:: output() const  {
    cout << "works on: " << workOnWho << endl;
}

#endif