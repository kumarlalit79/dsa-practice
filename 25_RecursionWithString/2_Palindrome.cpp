#include<iostream>
using namespace std;

bool checkPalindrome(string& str, int i, int j){
    // base case 
    if(i>j){
        return true;
    }
    
    // RR
    if (str[i] != str[j])
    {
        return false;
    }
    else{
        i++;
        j--;
        checkPalindrome(str, i, j);
    }
}

int main(){
    
    string str = "abbccbba";
    int i = 0;
    int j = str.length() - 1;
    bool ans = checkPalindrome(str, i, j);
    if(ans){
        cout << "palindrome";
    }
    else{
        cout << "not a palindrome";
    }
    return 0;
}