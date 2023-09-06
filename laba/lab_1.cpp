#include <iostream>
#include <stack>
#include<string.h>
#include<algorithm>
using namespace std;
void sortStack(stack<char> &s)
{
    string str = "";
    
    while (!s.empty()) {
        str += s.top();
        s.pop();
    }
    
    sort(str.begin(), str.end());
    
    for (char ch : str) {
        s.push(ch);
    }
}


int main() {
    string str;
    cout << "Enter ";
    getline(std::cin, str);
    
    // виділення пам'яті для масиву символів
    char* arr = new char[str.length() + 1];
    
    // копіювання рядка до масиву
    strcpy(arr, str.c_str());
    
    // виведення масиву на екран
    cout << "array " << arr << std::endl;
    
    // створення стеку та заповнення його елементами масиву
    stack<char> stack;
    for (int i = 0; i < str.length(); i++) {
        stack.push(arr[i]);
    }
    sortStack(stack);
    // виведення початкового стеку на екран
    cout << "stack";
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << std::endl;
    
    // створення додаткового стеку для сортування
    std::stack<char> sorted_stack;
    sortStack(stack);
    
    
    // виведення відсортованого стеку на екран
    cout << "better stack ";
    while (!sorted_stack.empty()) {
        cout << sorted_stack.top() << " ";
        sorted_stack.pop();
    }
    
    // звільнення пам'яті
    delete[] arr;
    return 0;
}