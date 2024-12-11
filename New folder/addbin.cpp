#include <iostream>
using namespace std;

// Structure for the node of doubly linked list
struct Node {
    int data;      // Holds a single bit (0 or 1)
    Node* prev;    // Pointer to the previous node
    Node* next;    // Pointer to the next node

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Class to represent binary numbers using a doubly linked list
class BinaryNumber {
private:
    Node* head;    // Head of the list (Least Significant Bit)
    Node* tail;    // Tail of the list (Most Significant Bit)

public:
    // Constructor to initialize an empty binary number
    BinaryNumber() : head(nullptr), tail(nullptr) {}

    // Function to insert a bit (0 or 1) at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the binary number from MSB to LSB
    void display() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data;
            temp = temp->prev;
        }
        cout << endl;
    }

    // Function to add two binary numbers stored in doubly linked lists
    static BinaryNumber add(BinaryNumber& bin1, BinaryNumber& bin2) {
        BinaryNumber result;
        Node* ptr1 = bin1.head;
        Node* ptr2 = bin2.head;
        int carry = 0;

        // Loop through both binary numbers and add bit by bit
        while (ptr1 || ptr2 || carry) {
            int sum = carry;

            // Add bit from bin1 if available
            if (ptr1) {
                sum += ptr1->data;
                ptr1 = ptr1->next;
            }

            // Add bit from bin2 if available
            if (ptr2) {
                sum += ptr2->data;
                ptr2 = ptr2->next;
            }

            // If sum is 1 or 3, set carry to 1 and insert 0 or 1 into result
            carry = sum / 2;
            result.insert(sum % 2);
        }

        return result;
    }
};

int main() {
    BinaryNumber bin1, bin2;

    // Input first binary number: 1011 (11 in decimal)
    cout << "Enter first binary number: ";
    bin1.insert(1);
    bin1.insert(0);
    bin1.insert(1);
    bin1.insert(1);

    // Input second binary number: 1101 (13 in decimal)
    cout << "Enter second binary number: ";
    bin2.insert(1);
    bin2.insert(1);
    bin2.insert(0);
    bin2.insert(1);

    // Display the binary numbers
    cout << "First binary number: ";
    bin1.display();
    cout << "Second binary number: ";
    bin2.display();

    // Add the two binary numbers
    BinaryNumber result = BinaryNumber::add(bin1, bin2);

    // Display the result
    cout << "Result of addition: ";
    result.display();

    return 0;
}
