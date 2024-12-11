#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;  // Highest precedence
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if the operator is left-associative
bool isLeftAssociative(char op) {
    return op != '^';  // Only '^' is right associative, others are left associative
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    // Iterate through each character in the infix expression
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is ')', pop from the stack until '(' is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Pop '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c) && isLeftAssociative(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
