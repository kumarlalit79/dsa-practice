#include<iostream>
#include<vector>
using namespace std;

int main(){

    // vector<int> vec(3,0); // size 0 here
    // for(int i : vec){
    //     cout << i << endl;
    // }


    vector<int> vec; 
    vec.push_back(10);
    vec.push_back(10);

    cout << "first val = " << vec.front();
    
    return 0;
}