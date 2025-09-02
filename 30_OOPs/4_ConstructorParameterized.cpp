#include<iostream>
using namespace std;

class Hero{
    private : 
    int health;
    public :
    char level;

    // creating parameterized constructor
    Hero(int health){
        cout << "this : " << this << endl;
        this -> health = health;
    }

    Hero(int health , char level){
        this -> health = health;
        this -> level = level;
    }
    void printConstructor(){
        cout << level << endl;
        cout << health << endl;
    }

    // getter
    int getHealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    // setter
    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
};

int main(){

    Hero h1(100);
    cout << "address of health : " << &h1 << endl;

    return 0;
}   