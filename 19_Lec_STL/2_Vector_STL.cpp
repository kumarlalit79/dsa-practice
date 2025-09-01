#include<iostream>
#include<vector> 
using namespace std;

int main(){

    vector<int> v1; // empty vector
    vector<int> v2(5); // 5 elements with garbage value
    vector<int> v3(5,10); // 5 elements, sab 10 
    vector<int> v4 = {50,30,50,70}; // initializer list

    //  Size aur Capacity 
    cout << "Size : " << v1.size() << endl;      // kitne elements hai
    cout << "Capacity : " << v1.capacity() << endl;  // memory me kitna space reserve hai
    

    // Element Add Karna (Insertion)
    v1.push_back(10);
    v1.push_back(100);

    // Traverse Karna
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " " << endl;
    }

    // Range-based for loop
    for (int x : v1)
    {
        cout << x << " " << endl;
    }
    
    //  Element Access Karna
    v1[0];          // 0th index element
    v1.at(2);       // 2nd index element with bounds checking
    v1.front();     // first element
    v1.back();      // last element
    

    // Element Delete Karna
    v1.pop_back();  // last element delete
    
    //  Poora Vector Clear Karna
    v1.clear();  // sab element hata dega
}