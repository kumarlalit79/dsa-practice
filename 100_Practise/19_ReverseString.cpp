#include<iostream>
using namespace std;

int reverse(string &str , int s, int e ){

    if (s > e)
    {
        return -1;
    }
    
    swap(str[s] , str[e]);
    s++;
    e--;
    return reverse(str,s,e);

}


int main(){

    string str = "abc";
    int s = 0;
    int e = str.length() - 1;
    reverse(str,s,e);
    cout << str;

    return 0;
}