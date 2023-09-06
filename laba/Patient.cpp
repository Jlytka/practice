#include<iostream>
using namespace std;
struct A{
	int operator+(const A&b){
   return 3;
   }
};
   int main(){
   A a,b;
   cout<<a+b;
}