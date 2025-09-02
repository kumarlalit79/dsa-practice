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
    Hero h1;

    // setting health and level through setter
    h1.setHealth(10);
    h1.setLevel('A');

    // getting health and level through getter
    cout << "Health : " << h1.getHealth() << endl;
    cout << "Level : " << h1.getlevel() << endl;
    return 0;
}