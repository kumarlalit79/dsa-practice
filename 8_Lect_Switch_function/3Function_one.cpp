#include<iostream>
using namespace std;

// power calculating program.
int power(int a , int b){
    int ans = 1;

    for(int i=1; i<=b; i++){
        ans = ans * a;
    }

    return ans;
}


int main(){

    int a,b;
    cout << "Enter a ";
    cin >> a ;
    
    cout << "Enter power ";
    cin >> b ;
  
    int ans = power(a , b);
    cout << ans;

    return 0;
}