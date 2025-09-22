#include <iostream>
using namespace std;


class kQueue{

    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freeSpot;
        int *next;

    // constructor
    public:
        kQueue(int n, int k){
            this->n = n;
            this->k = k;
            front = new int[k]; // front ko mujhko k size ka arr banana hai
            rear = new int[k];

            // front and rear ko initilize kr do
            for (int i = 0; i < k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }
            
            next = new int[n];
            // ab next ko update karna hai
            for (int i = 0; i < n; i++)
            {
                // har kisi element ke andar agla element daalna hota hai
                next[i] = i+1;
            }
            
            // last waale mai -1 daalna hota hai
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        void enqueue(int data, int qn){
         
            // overflow
            if (freeSpot == -1 )
            {
                cout << "No empty space is available" << endl;;                
                return;
            }

            // find first free index
            int index = freeSpot;

            // update free spot
            freeSpot = next[index];
            
            // check whther first elemnt
            if (front[qn-1] == -1)
            {
                front[qn-1] = index;
            }
            else{
                // link new element to the previous element
                next[rear[qn-1]] = index;
            }

            // update karo next ko
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn){

            // underflow
            if (front[qn-1] == -1)
            {
                cout << "Queue underflow" << endl;
                return -1;
            }
            
            // find index to pop
            int index = front[qn-1];

            // front ko aaghe badhao
            front[qn-1] = next[index];

            // free slot ko manage karo
            next[index] = freeSpot;

            freeSpot = index;

            return arr[index];  
        }

};


int main() {
    kQueue q(10, 3);  // 10-size array with 3 queues

    // Enqueue elements in different queues
    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 2);
    q.enqueue(40, 3);
    q.enqueue(50, 3);

    cout << "Dequeuing from Queue 1: " << q.dequeue(1) << endl; // 10
    cout << "Dequeuing from Queue 1: " << q.dequeue(1) << endl; // 20
    cout << "Dequeuing from Queue 2: " << q.dequeue(2) << endl; // 30
    cout << "Dequeuing from Queue 3: " << q.dequeue(3) << endl; // 40
    cout << "Dequeuing from Queue 3: " << q.dequeue(3) << endl; // 50
    cout << "Dequeuing from Queue 3 (Underflow): " << q.dequeue(3) << endl; // Queue empty

    return 0;
}
