#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node
    
    // Constructor to initialize node
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    
public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    // Destructor to free the memory
    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Insert a node at the beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode; // If the list is empty, make newNode both head and tail
        } else {
            newNode->next = head;     // Point new node's next to the current head
            head->prev = newNode;     // Point current head's prev to the new node
            head = newNode;           // Move head to new node
        }
    }

    // Insert a node at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode; // If the list is empty, make newNode both head and tail
        } else {
            newNode->prev = tail;  // Point new node's prev to the current tail
            tail->next = newNode;  // Point current tail's next to the new node
            tail = newNode;        // Move tail to the new node
        }
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) return; // List is empty

        Node* current = head;

        // Traverse the list to find the node
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // If node with value is found
        if (current != nullptr) {
            // If it's the head node
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            // If it's the tail node
            if (current == tail) {
                tail = current->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }
            // If it's a middle node
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current; // Free memory
        }
    }

    // Display the list from head to tail
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list from tail to head
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList list;
    
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertBeginning(5);
    
    cout << "Doubly Linked List (Forward): ";
    list.displayForward(); // Output: 5 10 20 30
    
    cout << "Doubly Linked List (Backward): ";
    list.displayBackward(); // Output: 30 20 10 5
    
    list.deleteNode(20); // Delete node with value 20
    
    cout << "Doubly Linked List after deleting 20 (Forward): ";
    list.displayForward(); // Output: 5 10 30
    
    cout << "Doubly Linked List after deleting 20 (Backward): ";
    list.displayBackward(); // Output: 30 10 5

    return 0;
}
