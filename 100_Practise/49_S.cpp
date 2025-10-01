#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &myStack, int x){

    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    
    int topelement = myStack.top();
    myStack.pop();
    solve(myStack,x);

    myStack.push(topelement);

}

void pushBottom(stack<int> &myStack, int x){
    solve(myStack,x);
}

int main() {
    
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(7);
    s.push(1);

    int x = 111;

    pushBottom(s,x);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    


    return 0;
}
