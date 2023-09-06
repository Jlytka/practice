#include<iostream>
using namespace std;

class fish {
private:
    string age;
public:
    string status;
    
    fish(const string& age): age(age) {}

    string getAge() const {
        return age;
    }

    void input() {
        cout << "enter status: ";
        cin >> status;
        cout << "enter age: ";
        cin >> age;
    }

    void output() const {
        cout << "status: " << status << endl;
        cout << "age: " << age << endl;
        
    }
};

class fish2 {
private:
    string hvist;
public:
    fish2(const string& hvist) : hvist(hvist) {}

    string getHvist() const {
        return hvist;
    }

    void HaveHvist(const string& hvist){
        this->hvist = hvist;
        cout << "mae hvist: " << hvist << endl;
    }

    virtual void speak() const {
        cout << "I am a fish2" << endl;
    }
};

class chameleon : public fish, private fish2 {
private:
    int typlap;
public:
    chameleon(const string& age): fish(age), fish2("") {}

    void set_lamy(int lapy){
        typlap = lapy;
    }

    bool Getlapy(){
        return (typlap > 1);
    }

    void ifmaelapy(){
        if (Getlapy())
            cout << "mae lapy" << endl;
        else
            cout << "ne mae" << endl;
    }

    void speak() const override {
        cout << "I love lapy" << endl;
    }
    
};

class betterchhameleon : private chameleon {
private:
    int newhvists;
public:
    betterchhameleon(const string& age): chameleon(age) {}

    int getnewhvist() const{
        return newhvists;
    }

    void maehvosty(){
        if (newhvists >= 1)
            cout << "you're lucky" << endl;
        else
            cout <<  "no." << endl;
    }

    
    void input(){
        fish::input();
        
        
    }
    void hvistInfo(){
        cout << "how much hvist do you have?";
        cin >> newhvists;
    }

    void output() const {
        fish::output();

    }

    void speak() const override {
        cout << "I am  better fish" << endl;
    }
};

class bird{
private:
    string age;

public:
    bird(const string& age): age(age) {}
    string krila;
    
    void input(){
        cout << "enter the length of the kryla: ";
        cin >> krila;
    }

    void output() const {
        cout << "kryla's length: " << krila << endl;
    }
};

class flyingchameleon:public betterchhameleon, private bird {
private:
    string liveon;
public:
    flyingchameleon(const string& age): betterchhameleon(age), bird("") {}
    
    void input(){
        betterchhameleon::input();
        cout << "enter where it lives: ";
        cin >> liveon; 
    }

    void output() const {
        betterchhameleon::output();
        cout << "live on: " << liveon << endl;
    }
};

int main(){
    fish a("fish");
    a.input();
    a.output();
    fish2 b("fish2");
    b.speak();
    chameleon d("noi");
    d.input();
    d.output();
    betterchhameleon cham("stiord");
    cham.input();
    
    cham.maehvosty();
    cham.output();
    flyingchameleon flycham("supercham");
    flycham.input();
    flycham.output();

    

    
    
    
}