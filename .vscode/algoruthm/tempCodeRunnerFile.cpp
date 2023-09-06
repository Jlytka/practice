#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
};

List* MAKENULL() {
    List* list = new List;
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

void INSERT(List *list, int value, int position) {
    Node *node = new Node;
    node->data = value;

    if (list->head == nullptr) {
        node->prev = nullptr;
        node->next = nullptr;
        list->head = node;
        list->tail = node;
    } else if (position == 0) {
        node->prev = nullptr;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    } else {
        Node *current = list->head;
        int i = 0;
        while (current->next != nullptr && i < position-1) {
            current = current->next;
            i++;
        }
        node->prev = current;
        node->next = current->next;
        if (current->next != nullptr) 
            current->next->prev = node;
        else 
            list->tail = node;
        
        current->next = node;
    }
}

void REMOVE(List *list, int position) {
    if (list->head == nullptr)
        return;
    else if (position == 0) {
        Node *temp = list->head;
        list->head = list->head->next;
        if (list->head != nullptr) {
            list->head->prev = nullptr;
        } 
        else {
            list->tail = nullptr;
        }
        delete temp;
    } 
    else {
        Node *current = list->head;
        int i = 0;
        while (current != nullptr && i < position) {
            current = current->next;
            i++;
        }
        if (current != nullptr) {
            current->prev->next = current->next;
            if (current->next != nullptr) 
                current->next->prev = current->prev;
             
            else 
                list->tail = current->prev;
            
            delete current;
        }
    }
}

void FIRST(List *list) {
    if (list->head != nullptr) 
        cout << "first elemnt: " << list->head->data << endl;
    else 
        cout << "list is empty " << endl;
    
}

void END(List *list) {
    if (list->tail != nullptr) 
        cout << "last element: " << list->tail->data << endl;
    else 
        cout << "list is empty " << endl;
    
}

int RETRIEVE(List *list, int position) {
    if (list->head == nullptr) 
        return -1;
    
    if (position < 0) 
        return -1;
    

    // Проходимо по списку в циклі, поки не досягнемо потрібної позиції
    Node *current = list->head;
    int i = 0;
    while (current != nullptr && i < position) {
        current = current->next;
        i++;
    }

    // Якщо позиція більша за кількість елементів у списку, повертаємо -1 або інший код помилки
    if (current == nullptr) 
        return -1;
    

    // Повертаємо значення елемента з потрібної позиції
    
    return current->data;
    
}
int NEXT(List *list, int pos) {
    Node *current = list->head;
    int i = 0;
    while(current != nullptr && i < pos){
        current = current->next;
        i++;
    }
    current = current->next;
    return current->data;
    
}


int PREV(List *list, int pos) {
    Node *current = list->head;
    int i = 0;
    while(current != nullptr && i < pos){
        current = current->next;
        i++;
    }
    current = current->prev;
    return current->data;
    
}


int LOCATE(List *list, int value) {
    Node *current = list->head;
    int position = 0;
    while (current != nullptr && current->data != value) {
        current = current->next;
        position++;
    }
    if (current == nullptr) 
        return -1; 
    else 
        return position; 
    
}

void PRINTLIST(Node* head) {
    if (head == nullptr) {
        cout << "list is empty" << endl;
        return;
    }

    cout << "list: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    List *list = MAKENULL();
    INSERT(list, 7, 0);
    INSERT(list, 6, 1);
    INSERT(list, 3, 2);
    INSERT(list, 12, 0);
    INSERT(list, 31, 2);
    PRINTLIST(list->head);
    
    
    cout << RETRIEVE(list, 2)  <<endl;
    int value;
    cout << "enter element: ";
    cin >> value;
    int position = LOCATE(list, value);
    if (position == -1) 
        cout << "error" << endl;
    else 
        cout << "found on " << position << endl;
    

    FIRST(list);
    END(list);   
    PRINTLIST(list->head);
    cout << NEXT(list, 2) << endl;
    cout << PREV(list, 1) << endl;
 
    REMOVE(list, 3);
    PRINTLIST(list->head);
    return 0;
}

