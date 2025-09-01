#include<iostream>
using namespace std;

long long int sqrRootInt(int num){
    int i = 0 , j = num;
    long long int mid = i + (j-i) / 2;
    long long int ans = -1;

    while (i<=j)
    {
        long long int sqrRoot = mid * mid;
        if (sqrRoot == num)
        {
            return mid;
        }
        if (sqrRoot < num)
        {
            ans = mid;
            i = mid + 1;
        }
        else{
            j = mid - 1;
        }
        mid = i + (j-i) / 2;
    }
    return ans;
}   

double decimalDigits(int n , int decimalPlaces , int tempSol){

    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < decimalPlaces; i++)
    {
        factor = factor / 10; // 0.1,0.01,0.001.. esa bante rahega.

        // baar baar add karna hai
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int num;
    cout << "Enter num : ";
    cin >> num;

    int tempSol = sqrRootInt(num);
    cout << "Answer is : " << decimalDigits(num , 3 , tempSol);   


    return 0;
}