#include<iostream>
using namespace std;

int power(int a , int b){
    // base case 
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
      
    // RR
    int pow = power(a,b/2);  
    if (b%2==0) 
    {
        return pow*pow;
    }
    else{
        return a*(pow*pow);
    }
}

int main(){
    
    int a;
    cout << "a : " ;
    cin >> a;
    int b;
    cout << "b : " ;
    cin >> b;
    
    int ans = power(a,b);
    cout << ans << endl;

    return 0;
}