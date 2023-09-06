#include <iostream>
#include <string>

int main() {
    std::string largestString;
    
    // Встановлюємо розмір рядка на максимально можливе значення
    largestString.reserve(std::string::npos);

    // Додаємо символи до рядка (необов'язково)
    largestString += "Hello, this is the largest possible string in C++.";

    std::cout << largestString << std::endl;
    
    return 0;
}
