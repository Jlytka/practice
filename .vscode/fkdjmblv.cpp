#include <iostream>
 using namespace std;
int main (){
cout.width(10); cout<<"ABCDF"<<'\n';
cout.fill('*'); cout.width (10); cout << "ABCDF" << "In";
cout.setf(ios::left); cout.width(10);
cout << "ABCDF" << "In";
cout.width(10); cout.precision (10);
cout<<123.234567<<"In";
cout.width(10);
cout.precision (6);
cout << 123.234567 << "In";
return 0;
}
