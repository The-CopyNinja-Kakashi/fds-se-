#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;

    // Traverse the postfix expression from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(c)) {
            s.push(string(1, c)); // Convert character to string and push
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string operand2 = s.top(); s.pop();
            string operand1 = s.top(); s.pop();
            
            // Form an infix expression with parentheses
            string infix = "(" + operand1 + " " + c + " " + operand2 + ")";
            
            // Push the resulting infix expression back onto the stack
            s.push(infix);
        }
    }

    // The final element in the stack will be the infix expression
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}
