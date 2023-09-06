#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}
    ~Stack() {}

    void push(char d) {
        if (topIndex == MAX_SIZE - 1) {
            cout << "Stack is full!" << endl;
            return;
        }
        data[++topIndex] = d;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        topIndex--;
    }

    char top() const {
        if (topIndex == -1) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        return data[topIndex];
    }

    int size() const {
        return topIndex + 1;
    }

    friend int countTotalElements(Stack s1, Stack s2) {
        return s1.size() + s2.size();
    }

    friend void restoreOriginalOrder(Stack& s1, Stack& s2) {
        vector<char> v;
        while (s1.size() > 0) {
            v.push_back(s1.top());
            s1.pop();
        }
        while (s2.size() > 0) {
            v.push_back(s2.top());
            s2.pop();
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            s1.push(v[i]);
        }
    }
};

int main() {
    Stack s1, s2;

    cout << "Enter elements for Stack 1 (one character at a time):" << endl;
    char c;
    while (cin >> c && c != '.') {
        s1.push(c);
    }

    cout << "Enter elements for Stack 2 (one character at a time):" << endl;
    while (cin >> c && c != '.') {
        s2.push(c);
    }

    cout << "Stack 1 before calling restoreOriginalOrder: ";
    while (s1.size() > 0) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    cout << "Stack 2 before calling restoreOriginalOrder: ";
    while (s2.size() > 0) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    int totalElements = countTotalElements(s1, s2);
    cout << "Total elements in both stacks: " << totalElements << endl;

    restoreOriginalOrder(s1, s2);

    cout << "Stack 1 after calling restoreOriginalOrder: ";
    while (s1.size() > 0) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    cout << "Stack 2 after calling restoreOriginalOrder: ";
    while (s2.size() > 0) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}
