#include<iostream>
#include<stack>
#include<queue>
using namespace std;


void reverseQueue(queue<int> &q){

    stack<int> s;

    // queue se saare element nikaalo or stack mai daal do
    while (!q.empty())
    {
        // queue se element nikaalke
        int element = q.front();
        q.pop();

        // push kardo stack mai
        s.push(element);
    }

    // ab stack se nikaalo or queue mai daalo
    while (!s.empty())
    {

        // stack se element nikaalo
        int element = s.top();
        s.pop();

        // queue mai daalo
        q.push(element);
    }
    
}

int main() {
    queue<int> q;

    // Adding elements to queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    queue<int> temp = q;  // Temporary copy for printing
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reversing the queue
    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
