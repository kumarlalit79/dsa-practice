#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &myStack , int number){
    // base case: agar stack empty hai ya number bada hai top se to number ko push kardo
    if (myStack.empty() || myStack.top() < number) {
        myStack.push(number);
        return;
    }

    int topElement = myStack.top();
    myStack.pop();

    // recursion
    sortedInsert(myStack, number);

    // wapas aate waqt element ko push kardo
    myStack.push(topElement);
}

void sortStack(stack<int> &myStack){
    // base case
    if (myStack.empty()) {
        return;
    }

    int topElement = myStack.top();
    myStack.pop();

    // recursion
    sortStack(myStack);

    // sorted manner me insert karna hai
    sortedInsert(myStack, topElement);
}

int main(){
    stack<int> st;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Stack before sorting: ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Stack after sorting (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}

/*

    Enter number of elements: 5
    Enter elements: 3 1 4 2 5


*/