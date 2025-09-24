#include<iostream>
using namespace std;

bool palindrome(string &str , int i , int j){

    if (i > j)
    {
        return true;
    }
    
    if (str[i] != str[j])
    {
        return false;
    }   
    else{
        i++;
        j--;
        palindrome(str,i,j);
    }
}

int main(){

    string str = "ffsfdsf";
    int i = 0;
    int j = str.length() -1;
    bool ans = palindrome(str,i,j);
    if (ans)
    {
        cout << "yes";
    }
    else{
        cout << "No";
    }

    return 0;
}