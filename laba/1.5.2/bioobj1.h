#ifndef obj1
#define obj1

#include <iostream>
using namespace std;

class bioobj1 {
private:
    string name;
public:
    string status;
    int age;
    bioobj1(const string& name): name(name) {}

    string getName() const {
        return name;
    }

    void input();

    void output() const;
};
void bioobj1:: input(){
    cout << "enter status: ";
    cin >> status;
    cout << "enter age: ";
    cin >> age;
}
void bioobj1:: output() const  {
    cout << "status: " << status << endl;
    cout << "age: " << age << endl;
    cout << "name: " << name << endl;
}
#endif