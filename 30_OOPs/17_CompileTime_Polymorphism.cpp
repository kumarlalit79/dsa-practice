#include<iostream>
using namespace std;

class A{

    public:
    void sayHello(){
        cout << "Hello Love Babbar" << endl;
    }

    void sayHello(string name){
        cout << "Hello Love Babbar" << name << endl;
    }

};

int main(){

    A obj;
    obj.sayHello();

    return 0;
}