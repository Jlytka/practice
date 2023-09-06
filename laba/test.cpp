#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    char* s = new char[x];
    for (int j = 0; j<x; j++){
        cin >> s[j];
    }
    int i;
    for(i=0;i<strlen(s);i++){
        if (s[i] == '+')
            s[i+1] = '-';
        if (s[i] == '-')
            s[i+1] = '+';
            
            
    }
    cout << s << endl;
}