#include<iostream>
#include<string>
#include<bitset>
#include<cstring>
using namespace std;

class DigitB{

private:
    string a;
    string b;
    
    string str;
public:
    DigitB (string a, string b) : a(a) , b(b){};
    void  ConvertToBinary(){
        int a_ = stoi(a , nullptr,  2);
        int b_ = stoi( b , nullptr, 2 );
        int c = a_ * b_;
        bitset<32> binary(c);
        str = binary.to_string();
        
       }
    string get_c(){
        return str;
    }
    
    char* charArr = new char[str.size() + 1];
        strcpy(charArr, str.c_str());


    string stringCheck(){
        
    }
};

int main(){
    DigitB a("1010", "1001");

    cout << a.ConvertToBinary();
    return 0;
}