#include<iostream>
#include<cstring>
using namespace std;

bool checkPalindrome(char str[] , int n){
    int s = 0;
    int e = n-1;

    while (s<=e)
    {
        if (str[s] != str[e])
        {
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

int main(){
    
    char str[20];
    cout << "Enter string : " << endl;
    cin >> str;
    int n = strlen(str);
    int check = checkPalindrome(str,n);
    if (check)
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}
