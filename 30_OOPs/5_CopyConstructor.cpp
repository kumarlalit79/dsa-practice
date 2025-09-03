#include<iostream>
using namespace std;

class Hero{
    private : 
    int health;

    public :
    char level;

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    } 
    void print(){
        cout << "Health : " << this -> health << endl;
        cout << "Level : " << this -> level << endl;
    }
};

int main(){

    
    Hero h1(90,'A');
    h1.print();
    
    // copying into new 
    cout << endl;
    
    Hero copy(h1);
    copy.print();

    return 0;
}   