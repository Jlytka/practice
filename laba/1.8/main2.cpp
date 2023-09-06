#include<iostream>
#include "dynamochild.h"

using namespace std;

int main(){
    int s;
    cin >> s;

    Array <int>arrray(s);
    
    arrray.input();

    arrray.output();
    arrray.search(3);
    
    Arraysmall <int>child(-3, 5);
    
    child.inputt();
    child.outputt();
    return 0;
}