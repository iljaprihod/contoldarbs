#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infixToPrefix(const std::string& infix) {
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    std::stack<char> operators;
    std::string prefix;

    for (char c : reversedInfix) {
        if (isalnum(c)) {
            prefix += c;
        } else if (c == ')') {
            operators.push(c);
        } else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += ' '; // Insert space between operators
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                prefix += ' '; // Insert space between operators
                prefix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        prefix += ' '; // Insert space between operators
        prefix += operators.top();
        operators.pop();
    }

    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter the infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string prefixExpression = infixToPrefix(infixExpression);
    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
