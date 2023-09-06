#include <iostream> 

using namespace std; 


class Expression{ 

protected: 

    char exp[50]; 


private: 

    bool start(char); 
    bool end(char); 
    bool zakr (char, char); 


public: 

    Expression(); 
    const char* get_str() { return exp; } 
    friend class Stack; 

}; 

 
 

Expression::Expression(){ 

    cout<<"enter expression: "; 
    cin.ignore();
    cin.getline(exp,50); 

} 



bool Expression::start(char symbol){ 

    if (symbol=='('||symbol=='['||symbol=='{') 

        return true; 

    else 

        return 0; 

} 

 
 

bool Expression::end(char symbol){ 

    if (symbol==')'||symbol==']'||symbol=='}') 

        return true; 

    else 

        return 0; 

} 

 
 

bool Expression::zakr(char a, char b){ 

    if (a=='('&&b==')'||a=='['&&b==']'||a=='{'&&b=='}') 

        return true; 

    else 

        return 0; 

} 

 