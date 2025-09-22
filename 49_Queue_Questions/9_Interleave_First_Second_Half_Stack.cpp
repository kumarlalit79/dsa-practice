#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    int half = n / 2;
    stack<int> s;

    // Step 1: Push first half into stack
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop stack elements back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move first half elements to back of queue
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Push first half into stack again
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave
    while (!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
