

#include<iostream>
#include<cmath>
using namespace std;
class Complex { 
private: 
    double module; 
    double angle; 
 
public: 
    Complex(double modul, double angl) { 
          
        module = modul;  
        angle = angl; 
    } 
 
    Complex operator+(const Complex& z) const { 
    double real = module * cos(angle) + z.module * cos(z.angle); 
    double imaginary = module * sin(angle) + z.module * sin(z.angle); 
    double mod = sqrt(real * real + imaginary * imaginary); 
    double ang = atan2(imaginary, real); 
    return Complex(mod, ang); 
    } 
  
    Complex operator-(const Complex& z) const { 
    double real = module * cos(angle) - z.module * cos(z.angle); 
    double imaginary = module * sin(angle) - z.module * sin(z.angle); 
    double mod = sqrt(real * real + imaginary * imaginary); 
    double ang = atan2(imaginary, real); 
    return Complex(mod, ang); 
    } 
 
    Complex operator*(const Complex& z) const { 
        double mod = module * z.module; 
        double ang = angle + z.angle; 
        return Complex(mod, ang); 
    } 
 
    Complex operator/(const Complex& z) const { 
        double mod = module / z.module; 
        double ang = angle - z.angle; 
        return Complex(mod, ang); 
    } 
 
    Complex operator^(double n) const { 
        double mod = pow(module, n); 
        double ang = angle * n; 
        return Complex(mod, ang); 
    } 
    
    Complex operator++() {
        angle += 1;
        return *this;
    }

    friend Complex& operator--(Complex& z);
       

    friend Complex root(const Complex& z);
       

 
   
    friend ostream& operator<<(ostream& os, const Complex& z) { 
        os << z.module << "cos(" << z.angle << ")+sin(" << z.angle << ")"; 
        return os; 
    } 
};


