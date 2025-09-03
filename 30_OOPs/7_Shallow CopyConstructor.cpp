#include<iostream>
#include <cstring>
using namespace std;

class Hero{
    private : 
    int health;

    public :
    char level;
    char *name;

    // shallow
    Hero(){
        cout << "Shallow constructor" << endl;
        name = new char[100];
    }
    
    // setter
    void setName(char name[]){
        strcpy(this -> name , name);
    }
    void print() {
        cout << "Name: " << name << ", Level: " << level << endl;
    }
    
};

int main(){

    Hero h1;
    h1.level = 'A';
    h1.setName("Batman");

    // Shallow copy using compiler default copy constructor
    Hero h2 = h1;  // <-- shallow copy

    cout << "Before changing h1:" << endl;
    h1.print();
    h2.print();

    // Change h1 name
    h1.name[0] = 'C';  // Batman → Catman

    cout << "\nAfter changing h1:" << endl;
    h1.print();
    h2.print();  // <-- ALSO CHANGED because same pointer
    
    return 0;
}   