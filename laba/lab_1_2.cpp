#include<iostream>
using namespace std;

class Mam1 {
private:
    string name;
public:
    string status;
    int age;
    Mam1(const string& name): name(name) {}

    string get_name() const {
        return name;
    }

    void input() {
        cout << "Enter status: ";
        cin >> status;
        cout << "Enter age: ";
        cin >> age;
    }

    void output() const {
        cout << "Status: " << status << endl;
        cout << "Age: " << age << endl;
        cout << "Name: " << name << endl;
    }
};

class Mam2 {
private:
    string job;
public:
    Mam2(const string& job) : job(job) {}

    string get_job() const {
        return job;
    }

    void WorksAt(const string& job){
        this->job = job;
        cout << "Works at: " << job << endl;
    }

    virtual void speak() const {
        cout << "I am a Mam2" << endl;
    }
};

class Dauther1 : public Mam1, private Mam2 {
private:
    int money_status;
public:
    Dauther1(const string& name): Mam1(name), Mam2("") {}

    void set_money(int money_){
        money_status = money_;
    }

    bool GetMoney(){
        return (money_status > 1);
    }

    void IfWorking(){
        if (GetMoney())
            cout << "Making money";
        else
            cout << "Sleeping";
    }

    void speak() const override {
        cout << "I am a Dauther1." << endl;
    }
    
};

class Dauther2 : private Dauther1 {
private:
    int amount_of_zaza;
public:
    Dauther2(const string& name): Dauther1(name) {}

    int get_amount_of_zaza() const{
        return amount_of_zaza;
    }

    void torh(){
        if (amount_of_zaza >= 1)
            cout << "You're lucky" << endl;
        else
            cout <<  "No." << endl;
    }

    
    void input(){
        Mam1::input();
        
        
    }
    void zaza_info(){
        cout << "How much zaza do you have";
        cin >> amount_of_zaza;
    }

    void output() const {
        Mam1::output();

    }

    void speak() const override {
        cout << "I am an artist" << endl;
    }
};

class Boyfriend{
private:
    string name;

public:
    Boyfriend(const string& name): name(name) {}
    string WorkOnWho;
    
    void input(){
        cout << "Enter the name of the boss: ";
        cin >> WorkOnWho;
    }

    void output() const {
        cout << "Boss's name: " << WorkOnWho << endl;
    }
};

class Son:public Dauther2, private Boyfriend {
private:
    string HelpsTo;
public:
    Son(const string& name): Dauther2(name), Boyfriend("") {}
    
    void input(){
        Dauther2::input();
        cout << "Enter who he helps to: ";
        cin >> HelpsTo; 
    }

    void output() const {
        Dauther2::output();
        cout << "Helps to: " << HelpsTo << endl;
    }
};

int main(){
    Mam2 k("mams");
    k.WorksAt("hospital");
    Mam1 a("Mary");
    a.input();
    a.output();
    Dauther1 d("Noita");
    d.input();
    d.output();
    Dauther2 zaza("marichka");
    zaza.input();
    zaza.zaza_info();
    zaza.torh();
    zaza.output();
    Son maksutko("oleg");
    maksutko.input();
    maksutko.output();

    

    
    
    
}