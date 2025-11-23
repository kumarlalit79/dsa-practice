#include<iostream>
using namespace std;


int main(){

    // creation
    int arr[3][4]; // total 12 element input mai dene hongge, 3X4=12

    cout << "Enter elements" << endl ;

    // taking input - row wise
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr[i][j];
    //     }   
    // }

    // taking input - col wise
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j][i];
        }   
    }
    
    // print
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }


    return 0;
}