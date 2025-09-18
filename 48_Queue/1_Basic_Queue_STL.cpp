#include<iostream>
#include<queue>
using namespace std;


int main(){

    // create a queue
    queue<int> q; 

    // insert element
    q.push(11);
    q.push(15);
    q.push(13);
    cout << "Size of queue : " << q.size() << endl; // 3
    
    // remove
    q.pop();
    cout << "Size of queue : " << q.size() << endl; // 2

    // check empty
    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;   
    }

    cout << "Queue's first element : " << q.front() << endl;// 15 
    

    return 0;
}