#include <iostream>
#include <ctime>

using namespace std;

struct INF{
    int key;
    char info;
};

void bubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void quickSort(INF arr[], int left, int right){
    int i = left, j = right;
    int pivot = arr[(left + right) / 2].key;

    while (i <= j){
        while (arr[i].key < pivot){
            i++;
        }

        while (arr[j].key > pivot){
            j--;
        }

        if (i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j){
        quickSort(arr, left, j);
    }

    if (i < right){
        quickSort(arr, i, right);
    }
}
 
const unsigned int NUM = 6000;
int A[NUM]; 
int B[NUM];           

void CreateArray(){
    srand(time(NULL));
    for (int i = 0; i < NUM; i++){
        A[i] = B[i] = (int)rand();
    }
}

void RestoreArray(){
    for (int i = 0; i < NUM; i++){
        A[i] = B[i];
    }
}

int main(){
    srand(time(NULL));

    CreateArray();

    clock_t begt, endt;
    begt = clock();
    bubbleSort(A, NUM);
    endt = clock();
    cout << "bubble Sort: " << (double)(endt - begt) / CLOCKS_PER_SEC << " seconds" << endl;

    RestoreArray();

    begt = clock();
    insertionSort(A, NUM);
    endt = clock();
    cout << "insertion Sort: " << (double)(endt - begt) / CLOCKS_PER_SEC << " seconds" << endl;

    RestoreArray();

    begt = clock();
    selectionSort(A, NUM);
    endt = clock();
    cout << "selection Sort: " << (double)(endt - begt) / CLOCKS_PER_SEC << " seconds" << endl;

    RestoreArray();

    INF arr[NUM];
    for (int i = 0; i < NUM; i++)
    {
        arr[i].key = A[i];
        arr[i].info = ' ';
    }

    begt = clock();
    quickSort(arr, 0, NUM - 1);
    endt = clock();
    cout << "quick Sort: " << (double)(endt - begt) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}