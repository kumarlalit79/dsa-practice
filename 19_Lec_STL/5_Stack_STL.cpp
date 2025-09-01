#include<iostream>
#include<stack>
using namespace std;

int main(){

    // creating stack
    stack<string> s;

    s.push("Lalit");
    s.push("Kumar");
    s.push("Arya");

    cout << "Top element :" << s.top() << endl; // o/p : arya

    s.pop(); // it'll remove top element

    // size of stack
    cout << "size of stack : " << s.size() << endl;

}