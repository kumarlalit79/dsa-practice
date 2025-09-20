#include <iostream>
using namespace std;

class InputRestrictedQueue {

    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    InputRestrictedQueue(int _size) {
        this->size = _size;
        arr = new int[_size];
        front = -1;
        rear = -1;
    }

    // Insert element ONLY from rear (since it's input restricted)
    bool enqueue(int data) {
        // Empty Queue Case
        if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
            return true;
        }

        // Full Queue Condition
        if ((front == 0 && rear == size - 1) ||
            (rear == (front - 1 + size) % size)) {
            cout << "Queue is full" << endl;
            return false;
        }

        // Wrap-around case
        if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = data;
        } 
        else {
            // Normal case: rear ko bas aage badha do
            rear++;
            arr[rear] = data;
        }
        return true;
    }

    // Deletion from FRONT
    int dequeueFront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // Single element case
        if (front == rear) {
            front = rear = -1;
        } 
        else if (front == size - 1) {
            front = 0; // wrap-around
        } 
        else {
            front++;
        }
        return ans;
    }

    // Deletion from REAR (allowed in input-restricted queue)
    int dequeueRear() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // Single element case
        if (front == rear) {
            front = rear = -1;
        } 
        else if (rear == 0) {
            rear = size - 1; // wrap-around rear to end
        } 
        else {
            rear--;
        }
        return ans;
    }

    // Get front element
    int getFront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main() {
    InputRestrictedQueue q(5);

    // Only enqueue from REAR
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);  // Queue is now full

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    // Dequeue from FRONT
    cout << "Dequeued from front: " << q.dequeueFront() << endl;
    cout << "Dequeued from front: " << q.dequeueFront() << endl;

    // Dequeue from REAR
    cout << "Dequeued from rear: " << q.dequeueRear() << endl;

    // Insert again (wrap-around example)
    q.enqueue(60);

    // Print remaining elements by removing them
    while (!q.isEmpty()) {
        cout << "Dequeued from front: " << q.dequeueFront() << endl;
    }

    return 0;
}
