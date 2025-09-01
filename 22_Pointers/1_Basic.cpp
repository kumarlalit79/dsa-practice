#include<iostream>
using namespace std;

int main(){
    // int num = 5;
    // cout << num << endl;
    // cout << "Address of num : " << &num << endl;

    // int *ptr = &num;
    // cout << "*Ptr value : " << *ptr << endl;
    // cout << "Ptr value : " << ptr;

    int num = 5;
    int a = num;
    cout << "a before" << num << endl;
    a++;
    cout << "a before" << num << endl;
    int *p = &num;
    cout << "before" << num << endl;
    (*p)++;
    cout << "after" << num << endl;

    // copying a pointer to another
    int *q = p;
    cout << p << "-" << q << endl;
    cout << *p << "-" << *q << endl;



    return 0;
}