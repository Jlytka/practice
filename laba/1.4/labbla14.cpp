#include<iostream>
using namespace std;
#include "Klitky.h"; 
#include "room.h"; 
#include "odin.h"; 
 
int main() {

    
    Odin odin;

    
    string name;
    string country;
    int day;
    int month;
    int year;
    cout << "Enter animal's name: ";
    cin >> name;
    cout << "Enter animal's country: ";
    cin >> country;
    cout << "Enter animal's birth date (day month year): ";
    cin >> day >> month >> year;
    Date birth_date(day, month, year);
    Animal animal(name, country, birth_date);

    
    int cost;
    cout << "Enter cost of the Odin operation: ";
    cin >> cost;
    cout << "Enter date of the Odin operation (day month year): ";
    cin >> day >> month >> year;
    Date date(day, month, year);

   
    odin.setAnimal(animal);
    odin.setDate(date);
    odin.setCost(cost);

    cout << "Animal's name: " << odin.getAnimal().getName() << endl;
    cout << "Animal's country: " << odin.getAnimal().getCountry() << endl;
    cout << "Animal's birth date: ";
    odin.getAnimal().getBirthDate().print();
    cout << "Date of the Odin operation: ";
    odin.getDate().print();
    cout << "Cost of the Odin operation: " << odin.getCost() << endl; 
    Room room1("66", 75, 89, cage); 
 
    room1.AddAnimal(animal, birth_date, 50); 
 
    room1.output(); 
    room1.ShortOutput(); 
    return 0;
}