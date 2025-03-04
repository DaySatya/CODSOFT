#include <iostream>

int main() {
    double num1, num2;
    char operation;
    double result;

    std::cout << "Welcome to the Simple Calculator!" << std::endl;


    std::cout << "Enter the first number: ";
    std::cin >> num1;


    std::cout << "Enter the second number: ";
    std::cin >> num2;


    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;


    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation. Please choose +, -, *, or /." << std::endl;
            break;
    }

    return 0;
}