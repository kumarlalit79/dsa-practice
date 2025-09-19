#include<iostream>
using namespace std;

class Queue{

    int *arr;
    int front;
    int rear;
    int size;

    // constructor
    public:
    Queue(int _size){
        this->size = _size;
        arr = new int[_size];
        front = 0;
        rear = 0;
    }

    // insertion
    void enqueue(int data){

        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    // deletion
    int dequeue(){

        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;  
        }
        else{

            int ans = arr[front];
            arr[front] = -1;
            front++;

            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int getFront(){
        if (front == rear) // check krlo empty h ya nahi
        {
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if (front == rear)
        {
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl;       // 10
    cout << "Dequeued: " << q.dequeue() << endl;       // 20
    cout << "Front element: " << q.getFront() << endl; // 30

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // This will print "Queue is full"

    while(!q.isEmpty()){
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;


    return 0;
}