#include<iostream>
using namespace std;

int main(){
    
    int a;
    cout << "Enter a : ";
    cin >> a;
    
    int b;
    cout << "Enter b : ";
    cin >> b;

    char op;
    cout << "Enter the operation you want to perform : ";
    cin >> op;

    switch (op)
    {
    case '+' : cout << a + b;
            break;
    case '-' : cout << a - b;
             break;
    case '*' : cout << a * b;
            break;
    case '/' : cout << a / b;
            break;
    case '%' : cout << a % b;
            break;        
    
    default: cout << "Invalid operation" ;
             break;
    }
    
}