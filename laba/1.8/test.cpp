#include <iostream>

using namespace std;

int main(){
    int* arr;
    int size = 3;
    for(int i = 0; i < size; i++){
        arr[i] = 1;

    }
    for (int i = 0; i < size; i++){
        cout << arr[i];
    }
    return 0;
}