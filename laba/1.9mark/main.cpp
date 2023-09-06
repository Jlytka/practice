#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int binaryToDecimal(string binaryNumber) {
    int decimalNumber = 0;
    int size = binaryNumber.size();
  
    for (int i = 0; i < size; i++) {
        if (binaryNumber[i] == '1') {
            decimalNumber += (1 << (size - i - 1));
        }
    }
  
    return decimalNumber;
}

string decimalToBinary(int decimalNumber, int length) {
    string binaryNumber = bitset<32>(decimalNumber).to_string();
    return binaryNumber.substr(32 - length);
}

string padZeros(string binaryNumber, int length) {
    string paddedNumber = binaryNumber;
  
    while (paddedNumber.length() < length) {
        paddedNumber = "0" + paddedNumber;
    }
  
    return paddedNumber;
}

string multiplyBinaryNumbers(string binaryNumber1, string binaryNumber2) {
    int decimalNumber1 = binaryToDecimal(binaryNumber1);
    int decimalNumber2 = binaryToDecimal(binaryNumber2);
    int result = decimalNumber1 * decimalNumber2;
  
    int maxLength = binaryNumber1.length() + binaryNumber2.length();
    string product = decimalToBinary(result, maxLength);
  
    return product;
}

int main() {
    string binaryNumber1, binaryNumber2;
  
    cout << "enter the first binary number: ";
    cin >> binaryNumber1;
  
    cout << "enter the second binary number: ";
    cin >> binaryNumber2;
  
    int maxLength = binaryNumber1.length() + binaryNumber2.length();
    binaryNumber1 = padZeros(binaryNumber1, maxLength);
    binaryNumber2 = padZeros(binaryNumber2, maxLength);
  
    string product = multiplyBinaryNumbers(binaryNumber1, binaryNumber2);
  
    
    size_t firstNonZero = product.find_first_not_of('0');
    if (firstNonZero != string::npos) {
        product = product.substr(firstNonZero);
    } else {
        product = "0";
    }
  
    cout << "product in binary: " << product << endl;
  
    return 0;
}