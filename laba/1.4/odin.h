#pragma once
#ifndef ODIN_H
#define ODINH
#include <iostream>
#include "Date.h";
#include "Animal.h";
using namespace std;


class Odin { 
 private: 
    Animal animal_; 
    Date date_; 
    int cost_; 
    public: 
  
    Odin() : animal_(), date_(), cost_(0) {} ;
   
    Odin(const Animal& animal, const Date& date, int cost) : animal_(animal), date_(date), cost_(cost) {} ;
 

    Odin(const Odin& other) : animal_(other.animal_), date_(other.date_), cost_(other.cost_) {} ;
 

    const Animal& getAnimal() const { return animal_; } ;
    const Date& getDate() const { return date_; } ;
    int getCost() const { return cost_; } ;
 

    Odin& setAnimal(const Animal& animal) { animal_ = animal; return *this; } ;
    Odin& setDate(const Date& date) { date_ = date; return *this; } ;
    Odin& setCost(int cost) { cost_ = cost; return *this; } ;

};

#endif

