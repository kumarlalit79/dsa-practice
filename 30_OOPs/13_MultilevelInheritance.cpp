#include<iostream>
using namespace std;

class Animal{
    public : 
    int age;
    int weight;

    public :
    void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal{

    // bina kuch yaha pe likhe bhi chal jayega

};

class Puppies : public Dog{



};

int main(){

    Puppies p;
    p.speak();

    return 0;
}