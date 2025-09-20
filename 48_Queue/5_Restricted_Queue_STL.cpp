#include <iostream>
#include <deque>
using namespace std;

class InputRestrictedQueue {
    deque<int> dq;  // STL deque use kiya

public:
    // Enqueue (sirf rear se allowed)
    void enqueue(int data) {
        dq.push_back(data);  // sirf peeche add karenge
    }

    // Dequeue from front
    int dequeueFront() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = dq.front();
        dq.pop_front();
        return val;
    }

    // Dequeue from rear
    int dequeueRear() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = dq.back();
        dq.pop_back();
        return val;
    }

    // Get front element
    int getFront() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return dq.front();
    }

    // Get rear element
    int getRear() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return dq.back();
    }

    bool isEmpty() {
        return dq.empty();
    }
};

int main() {
    InputRestrictedQueue q;

    // Enqueue from rear (only allowed end)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    // Dequeue from front
    cout << "Dequeued from front: " << q.dequeueFront() << endl;
    cout << "Dequeued from front: " << q.dequeueFront() << endl;

    // Dequeue from rear
    cout << "Dequeued from rear: " << q.dequeueRear() << endl;

    // Enqueue again
    q.enqueue(50);
    q.enqueue(60);

    while (!q.isEmpty()) {
        cout << "Dequeued from front: " << q.dequeueFront() << endl;
    }

    return 0;
}
