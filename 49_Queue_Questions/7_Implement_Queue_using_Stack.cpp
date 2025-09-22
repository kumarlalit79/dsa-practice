#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Push element into queue
    void push(int x) {
        s1.push(x);
    }

    // Pop element from queue
    void pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty! Cannot pop.\n";
            return;
        }

        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    // Get front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check if queue is empty
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;  // 10

    q.pop();
    cout << "Front element after pop: " << q.front() << endl;  // 20

    q.pop();
    cout << "Front element after second pop: " << q.front() << endl;  // 30

    q.pop();
    q.pop(); // extra pop - shows error handling

    return 0;
}
