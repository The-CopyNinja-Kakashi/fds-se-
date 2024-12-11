#include <iostream>
using namespace std;

// Define the Node structure for the doubly linked list
struct Node {
    int data;       // Stores binary digit (0 or 1)
    Node* next;     // Pointer to next node
    Node* prev;     // Pointer to previous node

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; // Head of the list
    Node* tail; // Tail of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert binary digit at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to compute the 1's complement of the binary number
    void onesComplement() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data = (temp->data == 0) ? 1 : 0; // Flip 0 to 1 and 1 to 0
            temp = temp->next;
        }
    }

    // Function to compute the 2's complement of the binary number
    void twosComplement() {
        // First, compute the 1's complement
        onesComplement();

        // Now, add 1 to the least significant bit
        Node* temp = tail;
        int carry = 1;
        while (temp != nullptr && carry) {
            if (temp->data == 0) {
                temp->data = 1;
                carry = 0; // No carry left
            } else {
                temp->data = 0;
                carry = 1; // Carry to the next higher bit
            }
            temp = temp->prev;
        }
    }
};

// Main function
int main() {
    // Create a doubly linked list to store binary number
    DoublyLinkedList binary;

    // Insert binary number 1011 (as an example)
    binary.insert(1);
    binary.insert(0);
    binary.insert(1);
    binary.insert(1);

    cout << "Original Binary Number: ";
    binary.display(); // Output: 1011

    // Compute 1's complement
    binary.onesComplement();
    cout << "1's Complement: ";
    binary.display(); // Output: 0100

    // Compute 2's complement
    binary.twosComplement();
    cout << "2's Complement: ";
    binary.display(); // Output: 0101

    return 0;
}
