#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &myStack , int x){

    // base case
    if (myStack.empty())
    {
        myStack.push(x);
        return ;
    }

    // top element ko side mai rakh do
    int topElement = myStack.top();
    myStack.pop();

    // recursive call
    insertAtBottom(myStack, x);

    // wapas jate wqt top element ko waps add kardo
    myStack.push(topElement);
    
}

void reverseStack(stack<int> &myStack){

    // base case
    if (myStack.empty())
    {
        return;
    }
    
    int topElement = myStack.top();
    myStack.pop();

    // RR - bacha hua stack ke liye
    reverseStack(myStack);

    // jab waapas aayenge
    insertAtBottom(myStack,topElement);
}

int main() {
    
stack<int> st;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Stack before reverse: ";
    stack<int> temp = st;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Stack after reverse: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}

/*
    how to run
    
    n = 4
    Elements: 10 20 30 40

*/