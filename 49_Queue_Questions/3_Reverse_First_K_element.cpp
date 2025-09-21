#include<iostream>
#include<stack>
#include<queue>
using namespace std;


queue<int> reverseKelement(queue<int> &q, int k){


    if (k > q.size()) {
        cout << "K cannot be greater than queue size!" << endl;
        return q;
    }

    // step 1 : starting ke element uthao(pop karo) or stack mai daalo
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front(); // jo queue mai front mai pada hai wo value nikaal li
        q.pop();
        s.push(val);
    }
    
    // step 2 : fetch from stack and push into queue
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // step 3 : fetch first n-k element from queue and push back
    int t = q.size() - k ; // queue ka size nikaal liye
    while (t--)
    {
        int val = q.front() ; // queue se element nikalane hai
        q.pop();
        q.push(val);
    }
    return q;


}

int main() {
    queue<int> q;

    // Queue me elements daal do
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3; // first k elements reverse karne hai

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Function call
    reverseKelement(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
