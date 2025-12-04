#include<iostream>
using namespace std;

class A{

    public:
    int a;
    int b;

    public:
    void operator+(A &obj) {
        int value1 = this->a;
        int value2 = obj.a;

        cout << "Output : " << value2 - value1 <<endl;
    }


    // () ka use krke dekhte hai
    void operator() (){
        cout << "Mai bracket hoon " << this->a << endl;
    }

};

int main(){

    A obj1 , obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2; // yaha + operator se call kya hai
    obj1();


    return 0;
}