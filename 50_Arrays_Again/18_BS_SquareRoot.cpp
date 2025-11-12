#include<iostream>
using namespace std;

int squareRoot(int n){

    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        int square = mid * mid;

        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double decimalPart(int n , int decimalCount , int intSoln){

    double factor = 1;
    double ans = intSoln;

    for (int i = 0; i < decimalCount; i++)
    {
        factor = factor / 10;

        // baar baar add krne ke liye
        for (double j = ans; j*j< n; j=j+factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main(){

    int n = 37;
    int intSoln = squareRoot(n);
    cout << "Square root is : " << decimalPart(n , 3 , intSoln);
        
    return 0;
}