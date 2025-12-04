#include<iostream>
using namespace std;


class Animal{

    public:
    void speak(){
        cout << "Animal is speaking" << endl;
    }
};

class Dog : public Animal{

    public:
    void speak(){
        cout << "Dog is barking" << endl;
    }

    // yaha hamne khud ki implementation daal di hai to ye call hoga jb object banega
};

class Cat : public Animal{
    public:
    // yaha hamne khud ki implementation nahi di hai, to animal waala call hoga
};

int main(){

    Dog obj;
    obj.speak();

    Cat obj2;
    obj2.speak();


    return 0;
}

// yaha pe khud ki implementation ham likh dete hai wo hi run time polymorphism hota hai