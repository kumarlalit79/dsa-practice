#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    // Push element onto stack
    void push(int x) {
        q.push(x);

        // Rotate the queue so that newly inserted element moves to front
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Remove element from stack
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        q.pop();
    }

    // Get top element of stack
    int top() {
        if (q.empty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        return q.front();
    }

    // Check if stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  // 30

    st.pop();
    cout << "Top element after pop: " << st.top() << endl;  // 20

    st.pop();
    cout << "Top element after second pop: " << st.top() << endl;  // 10

    st.pop();
    st.pop(); // extra pop - shows error handling

    return 0;
}
