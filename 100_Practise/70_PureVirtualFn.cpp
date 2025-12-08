#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void area() = 0;
};

class Circle : public Shape{
    public :
    void area() override{
        cout<<"area of circle" << endl;
    }
};

class Rectangle : public Shape{
    public :
    void area() override{
        cout<<"area of reactangle" << endl;
    }
};

int main() {
    
    Shape *s;

    Circle c;
    Rectangle r;

    s = &c;
    s->area();

    s = &r;
    s->area();
    
    

    return 0;
}