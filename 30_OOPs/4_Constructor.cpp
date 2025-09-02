#include<iostream>
using namespace std;

class Hero{
    private : 
    int health;
    public :
    char level;
    // creating constructor
    Hero(){
        cout << "Constructor call ho gaya" << endl;
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
    
    cout << "Constructor ke pehle" << endl;
    Hero h1;
    cout << "Constructor ke baad" << endl;
    return 0;
}   