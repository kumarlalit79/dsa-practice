#include<iostream>
using namespace std;


int factorial(int n){
    if (n==0)
    {
        return 1;
    }
    
    int ans = n * factorial(n-1);
    if (ans % 10 == 0)
    {
        return 0;
    }
    
    return ans;

}

int main(){

    int n = 4;

    cout << factorial(n);
    

    return 0;
}