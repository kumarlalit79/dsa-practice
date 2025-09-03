#include<iostream>
#include <cstring>
using namespace std;

class Hero{
    
    public :
    static int password;    

    // static method
    static int random(){
        cout << password << endl;
    }
};

// initilizing outside the class
int Hero::password=555123;

int main(){

    cout << Hero::password << endl;
    Hero::random();

    return 0;

}