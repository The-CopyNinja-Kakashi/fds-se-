#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;      // Array to store queue elements
    int front;     // Front of the queue
    int rear;      // Rear of the queue
    int capacity;  // Maximum capacity of the queue
    int size;      // Current size of the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Enqueue operation: Adds an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) { // If the queue is empty
            front = 0;
        }
        rear = (rear + 1) % capacity;  // Circular increment
        arr[rear] = value;
        size++;
        cout << value << " enqueued to the queue." << endl;
    }

    // Dequeue operation: Removes an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        front = (front + 1) % capacity;  // Circular increment
        size--;
        if (isEmpty()) {
            front = rear = -1; // Reset the queue when empty
        }
    }

    // Peek operation: Returns the element at the front of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Indicating empty queue
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Get the current size of the queue
    int getSize() {
        return size;
    }

    // Destructor to release memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);  // Creating a circular queue with a capacity of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(60);

    cout << "Front element after dequeue: " << q.peek() << endl;

    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}
