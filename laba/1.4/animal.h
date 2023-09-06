#ifndef BABAK
#define BABAK
#pragma once
#include <iostream>
#include "Date.h";

using namespace std;

class Animal { 
    private: 
    string name_; 
    string country_; 
    Date birth_date_; 
    public: 
    // Конструктор за замовчуванням 
    Animal() : name_(""), country_(""), birth_date_() {};
 
    // Конструктор з параметрами 
    Animal(const string& name, const string& country, const Date& birth_date) 
        : name_(name), country_(country), birth_date_(birth_date) {}; 
 
    // Конструктор копіювання 
    Animal(const Animal& other) 
        : name_(other.name_), country_(other.country_), birth_date_(other.birth_date_) {}; 
 
    // Селектори 
    string getName() const { return name_; }; 
    string getCountry() const { return country_; } ;
    Date getBirthDate() const { return birth_date_; } ;
 
    // Модифікатори з поверненням посилання на модифікований об'єкт 
    Animal& setName(const string& name) { name_ = name; return *this; } ;
    Animal& setCountry(const string& country) { country_ = country; return *this; } ;
    Animal& setBirthDate(const Date& birth_date) { birth_date_ = birth_date; return *this; } ;
}; 
#endif