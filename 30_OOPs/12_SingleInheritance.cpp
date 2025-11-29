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

int main(){

    Dog d;
    d.speak();

    return 0;
}