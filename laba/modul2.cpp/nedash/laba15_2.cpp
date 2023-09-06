#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int hexToDecimal(char hexDigit) {
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    } else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    } else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    }
    return -1; 
}

string hexToBinary(string hexadecimal) {
    stringstream binary;
    for (char hexDigit : hexadecimal) {
        int decimal = hexToDecimal(hexDigit);
        if (decimal == -1) {
            return "";  
        }
        for (int i = 3; i >= 0; --i) {
            binary << ((decimal >> i) & 1);
        }
    }
    return binary.str();
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 1;
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

int main() {
    string hex1, hex2;
    cout << "Enter the first hexadecimal number: ";
    cin >> hex1;
    cout << "Enter the second hexadecimal number: ";
    cin >> hex2;

    string binary1 = hexToBinary(hex1);
    string binary2 = hexToBinary(hex2);

    if (binary1.empty() || binary2.empty()) {
        cout << "Invalid hexadecimal number entered." << endl;
        return 0;
    }

    string sumBinary = binary1 + binary2;
    int sumDecimal = binaryToDecimal(sumBinary);

    cout << "Binary sum: " << sumBinary << endl;
    cout << "Decimal sum: " << sumDecimal << endl;

    return 0;
}
