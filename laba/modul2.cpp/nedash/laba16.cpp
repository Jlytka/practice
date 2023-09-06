#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArrayByAbsoluteValue(int arr[], int size) {
    sort(arr, arr + size, [](int a, int b) {
        if (std::abs(a) <= 1 && std::abs(b) <= 1) {
            return a < b;
        } else if (std::abs(a) <= 1) {
            return true;
        } else if (std::abs(b) <= 1) {
            return false;
        } else {
            return a < b;
        }
    });
}
int suma(int arr[], int size) {
    int sum = 0;
    int count = 0; 

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count++;
            if (count >= 2) {
                break; 
            }
        } else if (count == 1) {
            sum += arr[i]; 
        }
    }

    if (count < 2) {
        sum = 0; 
    }

    return sum;
}



int main(){



    int size;
    cin >> size;
  

    int* masyv = new int[size];
    int min = masyv[3];
    for (int i = 0; i < size; i++){
        cout << "enter element" << endl;
        cin  >> masyv[i];
    }
    for (int i = 0; i < size; i++){
        if (masyv[i] < min){
            min = masyv[i];
        }

    }
    cout << "minimal element is " << min << endl;
    cout << "suma between - elements = " << suma(masyv, size)<< endl;
    sortArrayByAbsoluteValue(masyv, size);
    cout << "sorted array :" << endl;
    for( int i = 0; i < size; i++){
        cout << masyv[i];
    }


    
}