#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;
    s.push(2);
    s.push(3);

    s.pop();
    
    cout << "Printing top element : " <<  s.top() << endl;
    
    if(s.empty()){
        cout << "Stack is emtpy" << endl;
    }
    else{
        cout << "Stack is not emtpy" << endl;   
    }
    
    cout << "Size of stack : " <<  s.size() << endl;

    return 0;
}