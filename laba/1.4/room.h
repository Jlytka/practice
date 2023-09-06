#include "Date.h";
#include <iostream>
#include "Odin.h";
#include <iomanip>
#include "Klitky.h"

class Room {
private:
  string size;
  int InfoSize=0;
  int number;
  float CostOfCleaning;
  RoomsType typeOfRoom;
  Odin* info=nullptr;
public:
  Room();
  Room(string,int,float,RoomsType);
  Room(const Room&);
  ~Room();

  string GetSize()const {return size;};
  int GetNumber()const {return number;};
  float GetCost()const {return CostOfCleaning;};
  RoomsType GetTypeOfRoom()const {return typeOfRoom;};
  Odin* GetInfo() const { return info; };

  Room& SetSize(const char* size);
  Room& SetNumber(int number);
  Room& SetCostOfCleaning(float coast);
  Room& SetTypeOfRoom(RoomsType type);

  void AddAnimal(const Animal&,const Date&,int);
  void output() const;
  void ShortOutput() const;
};

Room::Room()
:size(""), CostOfCleaning(0), typeOfRoom() {}

Room::Room(string size, int number, float cost, RoomsType type)
  : size(size), number(number),  CostOfCleaning(cost), typeOfRoom(type) {}

Room::Room(const Room& other)
 : size(other.size),
    InfoSize(other.InfoSize),
    number(other.number),
    CostOfCleaning(other.CostOfCleaning),
    typeOfRoom(other.typeOfRoom) {
  if (other.info != nullptr) {
    info = new Odin[other.InfoSize];
    for (int i = 0; i < other.InfoSize; ++i) {
      info[i].setCost(other.info[i].getCost());
      info[i].setDate(other.info[i].getDate());
      info[i].setAnimal(other.info[i].getAnimal());
    }
  }
}


Room::~Room() {
  delete[] info;
}

Room& Room::SetSize(const char* newSize) {
  size = newSize;
  return *this;
}

Room& Room::SetNumber(int newNumber) {
  number = newNumber;
  return *this;
}

Room& Room::SetCostOfCleaning(float newCost) {
  CostOfCleaning = newCost;
  return *this;
}

Room& Room::SetTypeOfRoom(RoomsType newType) {
  typeOfRoom = newType;
  return *this;
}

void Room::AddAnimal(const Animal& animal, const Date& date, int cost) {
  Odin newAnimal(animal, date, cost);
  if (info == nullptr) {
    InfoSize=1;
    info = new Odin[InfoSize];
    info[0].setCost(newAnimal.getCost());
    info[0].setAnimal(newAnimal.getAnimal());
    info[0].setDate(newAnimal.getDate());
  }
  else {
  Odin* newInfo = new Odin[InfoSize+1];
  for (int i = 0; i < InfoSize; ++i) {
    newInfo[i].setCost(info[i].getCost());
    newInfo[i].setAnimal(info[i].getAnimal());
    newInfo[i].setDate(info[i].getDate());
  }
  newInfo[InfoSize].setCost(newAnimal.getCost());
  newInfo[InfoSize].setAnimal(newAnimal.getAnimal());
  newInfo[InfoSize].setDate(newAnimal.getDate());

  delete[] info;

  info = newInfo;
  InfoSize++;
  }
}



void Room::output() const {

cout<<endl<<"output of all info: "<<endl;  
cout <<"Room number: " << number << endl;
cout << "Room size: " << size << endl;
cout << "Cost of cleaning: " << CostOfCleaning << endl;
cout << "Type of room: " << typeOfRoom << endl;
cout << "Animals in the room: " <<InfoSize<< endl;
for (int i = 0; i < InfoSize; ++i) {
    cout <<  setw(10) << left << "Name: " << info[i].getAnimal().getName() << endl
     << setw(10) << left << "Country: " << info[i].getAnimal().getCountry() << endl
     << setw(10) << left << "Date of birth: "<<info[i].getAnimal().getBirthDate().ToString() << endl
     << setw(10) << left << "Date of arrive: "<<info[i].getDate().ToString()<< endl 
     << setw(10) << left << "Cost: " << info[i].getCost() << endl
     << setw(20) << left << "Maintenance cost: " << info[i].getCost()<<endl;
     
}

}

void Room::ShortOutput() const {
  cout<<"output of short info: "<<endl;  
  cout << "Room number: " << number << ", Cost of cleaning: " << CostOfCleaning << endl;
}
