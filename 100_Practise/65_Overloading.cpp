#include<iostream>
using namespace std;

class A{
    public:
    virtual void work(){
        cout << "A class function" << endl;
    }
};

class B : public A{

    public:
    void work() override{
        cout << "B class function" << endl;
    }

};

int main(){

    A* a;
    B b;

    a = &b;
    a->work();



    return 0;
}