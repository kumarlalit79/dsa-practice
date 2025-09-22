#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump p[] , int n){

    int kami = 0; 
    int balance = 0;
    int start = 0; // start karna hai 0th index se

    for (int i = 0; i < n; i++)
    {
        balance = balance + p[i].petrol - p[i].distance; // balance nikal gaya yaha se

        // check balance -ve mai to nahi aa gaya
        if (balance < 0)
        {
            kami = kami + balance; // -ve aa gaya to means kami mai isko add kr liye ki itni kami padri hai
            start = i + 1; // start ko un -ve ke aage se start krna hoga. nai jgh se start kar re. new starting point basically ye hoga.
            balance = 0; //nai jgh se start kar re to balance ko 0 kardo dobara se
        }
    }

    if (kami + balance > 0)
    {
        return start;
    }
    else{
        return -1;
    }
}

int main() {
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr)/sizeof(arr[0]);

    int startIndex = tour(arr, n);

    if (startIndex != -1)
        cout << "Truck can start at petrol pump index: " << startIndex << endl;
    else
        cout << "No possible tour exists" << endl;

    return 0;
}
