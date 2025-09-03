#include<iostream>
#include <cstring>
using namespace std;

class Hero{
    private : 
    int health; 

    public :
    char level;
    char *name;

    Hero() {
        cout << "Constructor called" << endl;
        name = new char[100];
    }

    // Custom copy constructor for deep copy
    Hero(const Hero &other) {
        cout << "Deep copy constructor called" << endl;
        this->health = other.health;
        this->level = other.level;

        // Create a new memory block and copy content
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    void setName(const char name[]) {
        strcpy(this->name, name);
    }

    void print() {
        cout << "Name: " << name << ", Level: " << level << endl;
    }
    
};

int main(){

    Hero h1;
    h1.level = 'A';
    h1.setName("Batman");

    
    Hero h2 = h1;  

    cout << "Before changing h1:" << endl;
    h1.print();
    h2.print();

    // Change h1 name
    h1.name[0] = 'C';  // Batman → Catman

    cout << "\nAfter changing h1:" << endl;
    h1.print();
    h2.print();  
    
    return 0;
}   