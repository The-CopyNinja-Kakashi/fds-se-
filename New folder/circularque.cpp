#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;       // Array to store deque elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum capacity of the deque
    int size;       // Current size of the deque

public:
    // Constructor to initialize the deque
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Insert element at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at the front." << endl;
            return;
        }
        if (front == -1) {  // If deque is empty
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;  // Circular decrement
        }
        arr[front] = value;
        size++;
    }

    // Insert element at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at the rear." << endl;
            return;
        }
        if (rear == -1) {  // If deque is empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;  // Circular increment
        }
        arr[rear] = value;
        size++;
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from the front." << endl;
            return;
        }
        cout << "Deleted element from front: " << arr[front] << endl;
        if (front == rear) {  // Only one element in the deque
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;  // Circular increment
        }
        size--;
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from the rear." << endl;
            return;
        }
        cout << "Deleted element from rear: " << arr[rear] << endl;
        if (front == rear) {  // Only one element in the deque
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;  // Circular decrement
        }
        size--;
    }

    // Get the element at the front
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;  // Indicating empty deque
        }
        return arr[front];
    }

    // Get the element at the rear
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;  // Indicating empty deque
        }
        return arr[rear];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Get the current size of the deque
    int getSize() {
        return size;
    }

    // Destructor to release memory
    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5);  // Create a deque with capacity of 5

    dq.insertRear(10);  // Insert 10 at the rear
    dq.insertRear(20);  // Insert 20 at the rear
    dq.insertFront(30); // Insert 30 at the front
    dq.insertFront(40); // Insert 40 at the front
    dq.insertRear(50);  // Insert 50 at the rear

    cout << "Front element: " << dq.getFront() << endl; // Should print 40
    cout << "Rear element: " << dq.getRear() << endl;  // Should print 50

    dq.deleteFront();  // Delete element from front
    dq.deleteRear();   // Delete element from rear

    cout << "Front element after deletion: " << dq.getFront() << endl;  // Should print 30
    cout << "Rear element after deletion: " << dq.getRear() << endl;    // Should print 20

    cout << "Current size of deque: " << dq.getSize() << endl; // Should print 3

    return 0;
}
