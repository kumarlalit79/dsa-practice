#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    int i = 1;

    while (i <= n) { // for rows

        // printing space first
        int space = n - i;

        while (space) 
        // loop space baar chalega, jitne space utna loop
        {
            cout << " ";
            space = space - 1; 
        }

        // portion 2 stars 
        int j = 1;
        while (j <= i) { // for cols
            cout << j;
            j = j + 1;
        }
        
        // portion 3 stars
        int start = i - 1;
        while(start){
            cout << start;
            start = start - 1;
        }

        cout << endl;
        i = i + 1;
    }
}
