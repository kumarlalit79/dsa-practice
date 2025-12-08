#include<iostream>
using namespace std;

template <class P>

P add(P a, P b){
    return a - b;
}


int main(){

    cout << add(22.3,332.2) << endl;
    cout << add(22,33)<< endl;
    return 0;
}