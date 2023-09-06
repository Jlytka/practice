#pragma once
#ifndef DATE_H
#define DATEH
#include <ctime> 
#include <iostream> 

using namespace std;
class Date { 
    private: 
    int day_; 
    int month_; 
    int year_; 
public: 
    
    Date() ;
 
   
    Date(int day, int month, int year) : day_(day), month_(month), year_(year) {} ;
 
    Date(const Date& other) : day_(other.day_), month_(other.month_), year_(other.year_) {}; 
 
    int getDay() const { return day_; } ;
    int getMonth() const { return month_; } ;
    int getYear() const { return year_; } ;
 
    Date& setDay(int day) { day_ = day; return *this; } ;
    Date& setMonth(int month) { month_ = month; return *this; } ;
    Date& setYear(int year) { year_ = year; return *this; } ;
 
    void print() const ; 
    string ToString() const;

 

}; 

Date::Date(){

        time_t now = time(0); 
        tm* current_time = localtime(&now); 
 
        day_ = current_time->tm_mday; 
        month_ = current_time->tm_mon + 1; 
        year_ = current_time->tm_year + 1900; 

}

void Date::print() const{ 
    cout << day_ << "." << month_ << "." << year_ % 100 << endl; 
}

string Date::ToString() const {
    string day_str = to_string(day_);
    if (day_str.size() == 1) day_str = "0" + day_str;
    string month_str = to_string(month_);
    if (month_str.size() == 1) month_str = "0" + month_str;
    string year_str = to_string(year_ % 100);
    if (year_str.size() == 1) year_str = "0" + year_str;
    return day_str + "." + month_str + "." + year_str;
}
#endif
