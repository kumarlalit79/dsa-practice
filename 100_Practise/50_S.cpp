#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &myStack , int x){
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    
    int topelement = myStack.top();
    myStack.pop();

    insertAtBottom(myStack,x);

    myStack.push(topelement);

}


void reverse(stack<int> &myStack){

    if (myStack.empty())
    {
        return;
    }
    int topElement = myStack.top();
    myStack.pop();

    reverse(myStack);
    
    insertAtBottom(myStack , topElement);

}

int main() {
    
    stack<int> s;
    s.push(9);
    s.push(7);
    s.push(4);
    s.push(3);

    cout << "Before" << endl;
    stack<int> temp = s;
    while (!temp.empty())
    {
        cout << temp.top() << " "; 
        temp.pop();
    }
    reverse(s);

    cout << "After" << endl;
    while (!s.empty())
    {
        cout << s.top() << " "; 
        s.pop();
    }
    
    cout << endl;


    return 0;
}
