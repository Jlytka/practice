#include<iostream>
#include"Patient.h"

using namespace std;

class Patient{ 
private:
    string name;
    string adress;
    int number;
    string diagnosis;

public:

    void input(){
        cout<<"enter name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"enter adress: ";
        getline(cin, adress);
        cout<<"enter number: ";
        cin>>number;
        cout<<"enter diagnosis: ";
        cin >> diagnosis;
    }
    
    void shiza(string yourDiagnos){
        
        if (yourDiagnos==diagnosis)
        cout<<name<<endl; 
    }

   void numero(int a){
    
        if(a==number) 
            cout<<name<<endl;
    
    }
    void adresa(string yourAdresa){
        int check;
        check = adress.compare(yourAdresa);
        if (check == 0)
            cout<<name<<endl;

    }
};

int main(){
    cout<<"how many patients do you want? ";
    int am;
    cin>>am;
    Patient* obj=new Patient[am];
    
    for (int i=0;i<am;i++){
      obj[i].input(); 
    }
    string yourDiagnos;
    cout << "enter the diagnosis of patient: ";
    cin.ignore();
    cin >> yourDiagnos;
    for (int i=0;i<=am;i++){
        obj[i].shiza(yourDiagnos);
    }
    
    int a,b;
    cout << "enter an interval: ";
    cin >> a >> b;
    for (int i = 0; i<am;i++){
        for (int j = a; j<=b;j++){
            obj[i].numero(j);
        }
        
    }
    cout << "enter an adress of patient: ";
    string yourAdresa;
    cin.ignore();
    getline(cin, yourAdresa);
    for (int i = 0; i <am; i++){
        obj[i].adresa(yourAdresa);
    }
    delete[]obj;
    
}