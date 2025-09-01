#include<iostream>
#include<queue>
using namespace std;

int main(){

    // creating queue
    queue<string> q;

    // adding elements
    q.push("Lalit");
    q.push("Kumar");
    q.push("Arya");

    cout << "First Element : " << q.front() << endl;

    q.pop();
}