#include <iostream>
#include <string.h>

using namespace std;

typedef char nametype[30];

struct celltype{
    nametype element;
    celltype* next;
};

const int DICT_SIZE = 5;
typedef celltype* DICTIONARY[DICT_SIZE];

int hash(nametype x){
    int sum = 0;
    for (unsigned int i = 0; i < strlen(x); i++)
        sum += (int)x[i];
    return sum % DICT_SIZE;
}

void MAKENULL(DICTIONARY dict){
   for (int i = 0; i < DICT_SIZE; i++)
      dict[i]=nullptr; 
}


bool MEMBER(nametype x, DICTIONARY A){
    int index = ::hash(x);
    celltype* current = A[index];
    while (current != nullptr){
        if (strcmp(current->element, x) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void DELETE(nametype x, DICTIONARY& A){
    int index = ::hash(x);
    celltype* current = A[index];
    celltype* previous = nullptr;

    while (current != nullptr){
        if (strcmp(current->element, x) == 0){
            if (previous == nullptr)
                A[index] = current->next;
            else
                previous->next = current->next;
            
            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void INSERT(nametype x, DICTIONARY& A){
    int index = ::hash(x);
    celltype* newNode = new celltype;
    strcpy(newNode->element, x);
    newNode->next = nullptr;

    if (A[index] == nullptr){
        A[index] = newNode;
    }
    else{
        celltype* current = A[index];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void PRINT(DICTIONARY A){
    for (int i = 0; i < DICT_SIZE; i++){
        cout << "[" << i << "] ";
        celltype* current = A[i];
        while (current != nullptr){
            cout << current->element << " ";
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    DICTIONARY dict;
    MAKENULL(dict);
    char* strings[] = {
        "Heroes", "V-2 Schnider", "Station to Station", "Suffragette City", "Five Years",
        "Moonage Daydream", "Beauty and The Beast", "Breaking Glass", "Time", "Fame",
        "Ziggy Stardust", "Sound and Vision", "Let't Dance", "Rebel Rebel", "Ashes to Ashes"
    };

    for (int i = 0; i < 15; i++){
        INSERT(strings[i], dict);
    }

    PRINT(dict);

    if (MEMBER("Five Years",dict)) cout<<"Five Years is a member of dictionary" << endl;
    else cout << "Five Years is not a member of dictionary" << endl;

    DELETE("Five Years",dict);
    cout<<"delete Five Years:" << endl;
    PRINT(dict);

    if (MEMBER("All the Young Dudes",dict)) cout<<"All the Young Dudes is a member of dictionary" << endl;
    else cout << "All the Young Dudes is not a member of dictionary" << endl;

    cout << endl <<"enter name of song to add: ";
    nametype song;
    cin.getline(song, 30); 
    INSERT(song,dict);
    if (MEMBER("All the Young Dudes",dict)) cout << "All the Young Dudes is a member of dictionary" << endl;
    else cout<<"All the Young Dudes is not a member of dictionary" << endl;
    PRINT(dict);

    cout << endl << "makenull:" << endl;
    MAKENULL(dict);
    PRINT(dict);

    return 0;
}