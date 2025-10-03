#include<iostream>
#include<stack>
using namespace std;

void sortedIndex(stack<int> &myStack , int x){

    if (myStack.empty() || myStack.top() < x)
    {
        myStack.push(x);
        return;
    }
    
    int topElement = myStack.top();
    myStack.pop();

    sortedIndex(myStack,x);

    myStack.push(topElement);

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

int main(){

    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(7);
    s.push(3);

    stack<int> tem = s;
    cout << "Before" << endl;
    while (!tem.empty())
    {
        cout << tem.top() << " ";
        tem.pop();
    }
    cout << endl;

    sortStack(s);

    cout << "After" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}