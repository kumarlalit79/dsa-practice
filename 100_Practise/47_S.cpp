#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &inputStack , int size, int count){

    if (count == size/2)
    {
        inputStack.pop();
        return;
    }
    
    int topElement = inputStack.top();
    inputStack.pop();

    solve(inputStack, size, count+1);

    inputStack.push(topElement);
}

void deleteMiddle(stack<int> &inputStack , int size){
    int count = 0;
    solve(inputStack , size , count);
}

int main(){

    stack<int> s;
    s.push(4);
    s.push(8);
    s.push(12);
    s.push(9);
    s.push(5);

    stack<int> temp = s;
    cout << "Original : ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    
    deleteMiddle(s,5);
    cout << "After deletion : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    

    return 0;
}