#include<iostream>
using namespace std;

void reverse(string &str , int s){

    int n = str.length();

    if (s >= n-s-1)
    {
        return ;
    }
    swap(str[s] , str[s-n-1]);
    reverse(str,s+1);

}


int main(){

    string str = "abc";
    int s = 0;
    
    reverse(str,s);
    cout << str;

    return 0;
}