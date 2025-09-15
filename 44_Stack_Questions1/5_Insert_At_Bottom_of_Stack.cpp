#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &myStack, int x){

    // base case - check stack empty hai ya nahi
    if (myStack.empty())
    {
        myStack.push(x);
        return ;
    }

    // top element ko side mai rakh do
    int topElement = myStack.top();
    myStack.pop();

    // recursive call
    solve(myStack, x);

    // wapas jate wqt top element ko waps add kardo
    myStack.push(topElement);
    
}

void pushAtBottom(stack<int> &myStack, int x){
    solve(myStack, x);
    
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Enter element to push at bottom: ";
    int x;
    cin >> x;

    cout << "Before:" << endl;
    stack<int> temp = st;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    
    pushAtBottom(st, x); // bottom me push

    cout << "After:" << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}