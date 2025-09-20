#include <iostream>
using namespace std;

class DEQ {

    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    DEQ(int _size) {
        this->size = _size;
        arr = new int[_size];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x){

        // check if full or not
        if ((front == 0 && rear == size-1) || (rear == ( (front - 1 ) % (size-1) )))
        {
            return false;
        }
        else if(front == -1) // single element
        {
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){ // maintain circular
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x; // value ko us jgh pe store kr liya
        return true;
    }

    bool pushRear(int x){

        // check if full or not
        if ((front == 0 && rear == size-1) || (rear == ( (front - 1 + size) % size )))
        {
            return false;
        }
        else if(front == -1) // single element
        {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){ // maintain circular
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x; // value ko us jgh pe store kr liya
        return true;
    }

    int popFront(){
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;

        // for single element
        if (front == rear)
        {
            front = rear = - 1;
        }
        else if (front == size - 1) // agr front end mai pahuch chuka hai
        {
            front = 0; // to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }

    int popRear(){
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;

        // for single element
        if (front == rear)
        {
            front = rear = - 1;
        }
        else if (rear == 0) // agr front end mai pahuch chuka hai
        {
            rear = size-1; // to maintain cyclic nature
        }
        else{
            rear--;
        }
        return ans;
    }

    // Get front element
    int getFront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        if (front == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if ((front == 0 && rear == size-1) || (rear ==  (front - 1 + size) % size ))
        {
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    DEQ dq(5);

    cout << (dq.pushRear(10) ? "Inserted 10 at Rear\n" : "Failed\n");
    cout << (dq.pushRear(20) ? "Inserted 20 at Rear\n" : "Failed\n");
    cout << (dq.pushFront(5) ? "Inserted 5 at Front\n" : "Failed\n");
    cout << (dq.pushRear(30) ? "Inserted 30 at Rear\n" : "Failed\n");
    cout << (dq.pushFront(1) ? "Inserted 1 at Front\n" : "Failed\n");

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    cout << "Pop Front: " << dq.popFront() << endl;
    cout << "Pop Rear: " << dq.popRear() << endl;

    cout << (dq.pushRear(40) ? "Inserted 40 at Rear\n" : "Failed\n");
    cout << (dq.pushRear(50) ? "Inserted 50 at Rear\n" : "Failed (Queue Full)\n");

    while (!dq.isEmpty()) {
        cout << "Pop Front: " << dq.popFront() << endl;
    }

    cout << "Queue empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

