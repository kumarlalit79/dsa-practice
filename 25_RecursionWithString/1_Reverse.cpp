#include<iostream>
using namespace std;

void reverse(string& str, int i, int j){
    // base case 
    if(i>j){
        return ;
    }
    
    // RR
    swap(str[i] , str[j]);
    i++;
    j--;
    reverse(str, i, j);
}

int main(){
    
    string str = "babbar";
    int i = 0;
    int j = str.length() - 1;
    reverse(str, i, j);
    cout << str << endl;
    return 0;
}