#include<iostream>
#include<string>
#include<bitset>
using namespace std;

class DigitB{

private:
    string a;
    string b;
    
    int c;
public:
    DigitB (string a, string b) : a(a) , b(b){};
    string ConvertToBinary(){
        int a_ = stoi(a , nullptr,  2);
        int b_ = stoi( b , nullptr, 2 );
        int c = a_ * b_;
        bitset<32> binary(c);

        string c_ = to_string(c);

        return c_;

        

    }

};

int main(){
    DigitB a("1010", "1001");

    cout << a.ConvertToBinary();

    return 0;
}