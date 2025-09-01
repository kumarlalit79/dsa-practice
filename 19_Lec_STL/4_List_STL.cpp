#include<iostream>
#include<list>
using namespace std;

int main(){

    // Creating list
    list<int> l;

    // Adding element
    l.push_back(10);
    l.push_back(120);
    l.push_back(100);
    l.push_back(80);
    l.push_back(20);
    l.push_back(90);

    // printing elements
    for(int x : l){
        cout << x << " " << endl;
    }

    // removing
    l.pop_front();
    l.pop_back();
    cout << "Removing : " << endl;
    for(int x : l){
        cout << x << " " << endl;
    }
    
    // copying existing list into new list
    cout << "copying existing list into new list" << endl;
    list<int> new_list(l);
    for(int x : new_list){
        cout << x << " " << endl;
    }
} 