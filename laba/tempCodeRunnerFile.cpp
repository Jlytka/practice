include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Patient{ 
private:
    string name;
    string adress;
    int number;
    string diagnos;

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
        
        cin >> diagnos;
    }
    string getName(){
        return name;
    }
    string getAdress(){
        return adress;
    }
    int getNumber(){
        return number;
    }
    string getDiagnos(){
        return diagnos;
    }
    
    void shiza(string yourDiagnos){
        
        if (yourDiagnos==diagnos)
        cout<<name<<endl;
        
   }

   void numero(int a){
    
    
        if(a==number) 
            cout<<name<<endl;
    
   }
    void iknowwhereyoulive(string adresa){
        int check;
   
        check = adress.compare(adresa);
        if (check == 0)
            cout<<name<<endl;
        else
            cout << "blya";

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
    string diagnosss;
    cout << "enter the diagnosis of patient: ";
    cin.ignore();
    cin >> diagnosss;
    for (int i=0;i<=am;i++){
        obj[i].shiza(diagnosss);
    }
    
    int a,b;
    cout << "enter an interval: ";
    cin >> a >> b;
    for (int j = 0; j<am;j++){
        for (int x = a; x<b;x++){
            obj[j].numero(x);
        }
        
        
    }
    cout << "enter an adress of patient: ";
    
    string xx;
    cin.ignore();
    getline(cin, xx);
    for (int i = 0; i <am; i++){
        obj[i].iknowwhereyoulive(xx);
    }
    
    
}