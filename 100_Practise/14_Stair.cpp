#include<iostream>
using namespace std;

int stair(int n){
    //base case
    if( n < 0){
        return 0;
    }
    if(n == 0) 
        return 1;
    
    //recurrence relation
    int ans = stair(n-1) + stair(n-2);
    return ans;
}

int main(){

    int n;
    cout << "enter number :" << endl;
    cin >> n; 
    cout << stair(n) << endl; 
}