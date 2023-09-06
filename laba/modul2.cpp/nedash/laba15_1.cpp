#include <iostream>
#include <string>
#include <sstream>
#include<algorithm>
using namespace std;

string decToBinary(int decimal) {
    stringstream binary;
    while (decimal > 0) {
        binary << (decimal % 2);
        decimal /= 2;
    }
    string binaryString = binary.str();
    reverse(binaryString.begin(), binaryString.end());
    return binaryString;
}

string decToOctal(int decimal) {
    stringstream octal;
    while (decimal > 0) {
        octal << (decimal % 8);
        decimal /= 8;
    }
    string octalString = octal.str();
    reverse(octalString.begin(), octalString.end());
    return octalString;
}

string decToHexadecimal(int decimal) {
    stringstream hexadecimal;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal << remainder;
        } else {
            hexadecimal << static_cast<char>('A' + remainder - 10);
        }
        decimal /= 16;
    }
    string hexadecimalString = hexadecimal.str();
    reverse(hexadecimalString.begin(), hexadecimalString.end());
    return hexadecimalString;
}

int main() {
    int decimalNumber;
    cout << "enter number: ";
    cin >> decimalNumber;

    string binary = decToBinary(decimalNumber);
    string octal = decToOctal(decimalNumber);
    string hexadecimal = decToHexadecimal(decimalNumber);

    cout << "binary: " << binary << endl;
    cout << "octal: " << octal << endl;
    cout << "hexademical: " << hexadecimal << endl;

    return 0;
}
