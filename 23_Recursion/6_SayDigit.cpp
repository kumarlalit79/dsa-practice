#include<iostream>
using namespace std;

void sayDigit(int n, string arr[]){
    //base case
    if( n == 0){
        return ;
    }
    
    //processing
    int digit = n%10;
    n = n/10;
    
    //recurrence relation
    sayDigit(n,arr);
    cout << arr[digit];    
}

int main(){

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cout << "enter number :" << endl;
    cin >> n; 
    sayDigit(n,arr);
    
}