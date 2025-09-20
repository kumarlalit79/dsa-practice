#include <iostream>
#include <queue>
using namespace std;

int main(){

    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl; // 12
    cout << d.back() << endl; // 14

    cout << endl;

    d.pop_front(); // ab front and rear dono pointer 14 ko point kar rahe honge
    cout << d.front() << endl; 
    cout << d.back() << endl; 

    cout << endl;

    d.pop_back();
    // d.push_back(15);
    if (d.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }

    return 0;
}