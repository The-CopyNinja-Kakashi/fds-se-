#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> pq;  // Store elements in a vector

public:
    // Insert an element into the priority queue
    void push(int value) {
        pq.push_back(value);  // Simply push the value into the vector
    }

    // Remove and return the element with the highest priority (maximum element)
    int pop() {
        if (pq.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;  // Return -1 if the queue is empty
        }

        // Find the maximum element (highest priority)
        int maxIndex = 0;
        for (int i = 1; i < pq.size(); i++) {
            if (pq[i] > pq[maxIndex]) {
                maxIndex = i;
            }
        }

        // Get the maximum element and remove it from the queue
        int maxValue = pq[maxIndex];
        pq.erase(pq.begin() + maxIndex);  // Remove the element

        return maxValue;
    }

    // Get the element with the highest priority (but don't remove it)
    int top() {
        if (pq.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;  // Return -1 if the queue is empty
        }

        // Find the maximum element (highest priority)
        int maxValue = pq[0];
        for (int i = 1; i < pq.size(); i++) {
            if (pq[i] > maxValue) {
                maxValue = pq[i];
            }
        }

        return maxValue;
    }

    // Check if the priority queue is empty
    bool empty() {
        return pq.empty();
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(5);

    cout << "The highest priority element is: " << pq.top() << endl;

    cout << "Popping the highest priority element: " << pq.pop() << endl;

    cout << "The highest priority element now is: " << pq.top() << endl;

    return 0;
}
