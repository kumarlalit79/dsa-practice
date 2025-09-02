#include<iostream>
using namespace std;

class Hero{
    private : 
    int health;

    public :
    char level;

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
    
    // static allocation
    Hero h1;
    cout << "Health" << h1.getHealth();
    cout << "Level" << h1.getlevel();


    // dynamic allocatoin
    Hero *h2 = new Hero();

    // approach 1
    cout << "Health" << (*h2).getHealth() << endl;
    cout << "Level" << (*h2).getlevel() << endl;

    // approach 2

    h2 -> setHealth(100);
    h2 -> setLevel('A');

    cout << "Health" << h2 -> getHealth() << endl;
    cout << "Level" << h2 -> getlevel() << endl;

    return 0;
}   