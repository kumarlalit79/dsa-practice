#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    int half = n / 2;

    queue<int> newQ;

    // Step 1: Move first half to newQ
    for (int i = 0; i < half; i++) {
        newQ.push(q.front());
        q.pop();
    }

    // Step 2: Interleave
    while (!newQ.empty()) {
        // First element from first half
        q.push(newQ.front());
        newQ.pop();

        // Then element from second half
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
