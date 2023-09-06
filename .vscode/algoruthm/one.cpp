#include <iostream>

using namespace std;

struct celltype{
    int el;
    celltype *next;
        
};

celltype* MAKENULL() {
    celltype* List = nullptr;
    return List;
}

int END(celltype* List) {

    while (List->next!= nullptr) 
        List = List->next;
    

    if (List->next == nullptr) 
        return List->el;
    
}

int FIRST(celltype* List) {
    if (List == nullptr)
        cout << "list is empty" << endl;
    else 
        return List->el;
    

}

void INSERT(celltype* List) {
    cout << "position to insert: ";
    int posit;
    cin >> posit;
    cout << "element  to insert: ";
    int inserted;
    cin >> inserted;
    celltype* newList = new celltype;
    newList->el = inserted;
    if (posit == 0 || List == NULL) {
        newList->next = List;
        List = newList;
    }
    else {
     celltype* curr = List;        
     for (int i = 0; i < posit - 1 && curr->next != NULL; i++) {
        curr = curr->next;
        }    
        newList->next = curr->next;       
        curr->next = newList;
    }
}

void DELETE(celltype* List) {
    celltype d;
    cout << endl << "element  to delete: ";
    cin >> d.el;
    celltype* curr=List;
    celltype* prev = nullptr;
    while (curr != nullptr) {
        if (curr->el == d.el) {
            if (prev == nullptr)
                List = List->next;
            else
                prev->next = curr->next;
            delete curr;
            return;

        }
        prev = curr;
        curr = curr->next;
    }
}

int LOCATE(celltype* List) {
    int place = 0;
    celltype elm;
    cout << "element position to found ";
    cin >> elm.el;
    while (List != nullptr) {

        if (List->el == elm.el)
            break;
        List = List->next;
        place++;
    }
    cout << " position of the element: " << place << endl;
    return place;

}

int RETRIEVE(celltype* List) {
    celltype posit;
    int index = 0, place=0;
    cout << "enter the position of element: ";
    cin >> posit.el;
    while (List != nullptr) {
        List = List->next;
        place++;
        if (place == posit.el) {
            //cout <<"element value by index: " << List->el<<endl;
            return List->el;
        }
    }
}


celltype* NEXT(celltype *List ) {
    return List->next;

}

void PRINTLIST(celltype* List) {
    celltype* curr = List;
    if ( List==nullptr) 
        cout << "list is empty"<< endl;
    
    else {
        while (curr != nullptr) {
            cout << curr->el << ' ';
            curr = curr->next;
        }
    }
}
int main() {
    celltype* List = nullptr;
    MAKENULL();
    List = new celltype{ 1, nullptr };
    List->next = new celltype{ 2, nullptr };
    List->next->next = new celltype{ 3, nullptr };
    List->next->next->next = new celltype{ 45, nullptr };
    List->next->next->next->next= new celltype{ 6, nullptr };
    
    PRINTLIST(List);
    END(List);
    FIRST(List);
    DELETE(List);
    INSERT(List);
    LOCATE(List);
    
    int a = RETRIEVE(List);
    cout << a<< endl;
    NEXT(List);
    PRINTLIST(List);
    return 0;

}