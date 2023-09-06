#include <iostream>
#include <stack>
#include <vector>

class Stack {
private:
    std::stack<char> elements;

public:
    void push(char c) {
        elements.push(c);
    }

    char pop() {
        char c = elements.top();
        elements.pop();
        return c;
    }

    int size() {
        return elements.size();
    }

    std::stack<char>& getElements() {
        return elements;
    }

    void setElements(const std::stack<char>& newElements) {
        elements = newElements;
    }
};

int totalSize(Stack& stack1, Stack& stack2) {
    return stack1.size() + stack2.size();
}

void restoreOrder(Stack& stack1, Stack& stack2, std::vector<char>& sequence1, std::vector<char>& sequence2) {
    std::stack<char> tempStack1, tempStack2;

    while (!stack1.getElements().empty()) {
        sequence1.push_back(stack1.pop());
    }

    while (!stack2.getElements().empty()) {
        sequence2.push_back(stack2.pop());
    }

    for (int i = sequence1.size() - 1; i >= 0; i--) {
        tempStack1.push(sequence1[i]);
    }

    for (int i = sequence2.size() - 1; i >= 0; i--) {
        tempStack2.push(sequence2[i]);
    }

    stack1.setElements(tempStack1);
    stack2.setElements(tempStack2);
}

int main() {
    Stack stack1, stack2;
    std::vector<char> sequence1, sequence2;

    stack1.push('A');
    stack1.push('B');
    stack1.push('C');

    stack2.push('X');
    stack2.push('Y');
    stack2.push('Z');

    int total = totalSize(stack1, stack2);
    std::cout << "Total number of elements in the stacks: " << total << std::endl;

    restoreOrder(stack1, stack2, sequence1, sequence2);

    std::cout << "Restored sequence in stack 1: ";
    while (!stack1.getElements().empty()) {
        char c = stack1.pop();
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << "Restored sequence in stack 2: ";
    while (!stack2.getElements().empty()) {
        char c = stack2.pop();
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
