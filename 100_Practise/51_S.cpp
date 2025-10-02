#include<iostream>
#include<stack>
using namespace std;

void sortedIndex(stack<int> &mystack , int x){

    if (mystack.empty() || mystack.top() < x)
    {
        mystack.push(x);
        return;
    }
    int topElement = mystack.top();
    mystack.pop();  

    sortedIndex(mystack,topElement);
    mystack.push(topElement);
}

void sortStack(stack<int> &myStack){

    if (myStack.empty())
    {
        return;
    }

    int topElement = myStack.top();
    myStack.pop();

    sortStack(myStack);

    sortedIndex(myStack, topElement);
}

int main() {
    
    stack<int> s;
    s.push(9);
    s.push(7);
    s.push(4);
    s.push(3);

    

    return 0;
}
