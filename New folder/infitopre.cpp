#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> s;
    
    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            s.push(string(1, c)); // Push the operand (as a string) to the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            
            // Form an infix expression by adding parentheses around the operands
            string infix = "(" + operand1 + " " + c + " " + operand2 + ")";
            
            // Push the resulting infix expression back onto the stack
            s.push(infix);
        }
    }
    
    // The final element in the stack is the infix expression
    return s.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    
    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;
    
    return 0;
}

