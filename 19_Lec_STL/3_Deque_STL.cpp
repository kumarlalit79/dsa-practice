#include<iostream>
#include<deque>
using namespace std;

int main(){
    
    // Creating
    deque<int> d;

    // adding element
    d.push_front(1);
    d.push_front(2);

    // traversing
    for (int i = 0; i <= d.size(); i++)
    {
        cout << d[i] << " " << endl;
    }

    // removing element
    d.pop_back();
    d.pop_front();

    // baki isme bhi vector waale operations perform kar sakte hai
}