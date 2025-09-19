#include<iostream>
using namespace std;


class CircularQueue{

    int *arr;
    int front ;
    int rear ;
    int size;

    // constructor
    public:
    CircularQueue(int _size){
        this->size = _size;
        arr = new int[_size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int data){
        if ((front == 0 && rear == size-1) || (rear == ( (front - 1 + size) % size )))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if(front == -1) // that means hamare pass first element aaya hai push krne ke liye
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size-1 && front != 0) // agr rear end tk pahuch chuka hai to rear ko starting mai bhej do
        {
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
        return true;
    }

    int dequeue(){
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

     int getFront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return (front == -1);
    }
};

int main(){

    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element: " << q.getFront() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // yaha wrap-around hoga ya full hoga

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}