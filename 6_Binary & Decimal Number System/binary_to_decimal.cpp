#include<iostream>
#include <math.h>
using namespace std;

int main(){

    int n;
    cout << "Enter n : ";
    cin >> n;
    
    int ans = 0;
    int i = 0;

    while(n != 0){
        int digit = n % 10; // yaha input mai binary number daalna or ye krke ek ek digit ham uth lenge n ki  

        if( digit == 1){
            ans = ans + pow(2,i);
        }
        n = n / 10; // binary to decimal mai divide karte
        i++;
    }
    cout <<"Answer is : " << ans << endl;
}