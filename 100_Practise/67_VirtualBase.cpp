#include <iostream>
using namespace std;

class A {
    public:

    int value;

    A() {

    value = 100;

    cout << "A Constructor\n";
    }

};

class B : virtual public A {

    public:
        B() {
        cout << "B Constructor\n";
    }
};

class C : virtual public A {
    public:
    C(){
    cout << "C Constructor\n";
    }

   

};

class D : public B, public C {
    public:
        D() {
        cout << "D Constructor\n";
    }

};

int main() {
    D obj;
    cout << "Value = " << obj.value << endl;
    return 0;
}