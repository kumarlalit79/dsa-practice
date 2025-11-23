#include<iostream>
#include<limits.h>
using namespace std;

int largestRowSum(int arr[][4] , int row , int col){
    
    int maxi = INT_MIN;
    int rowIndex = -1;
    
    // row wise sum nikaal liya
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum; // maxi ke andar total sum store karwa diya
            rowIndex = i; // and index uska rowindex mai
        }
    }   
    cout << "The maximum sum is : " << maxi << endl;
    return rowIndex;
}

int main(){

    int arr[3][4];
    cout << "Enter the elements in the 2D array : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Max row is at index : " << largestRowSum(arr,3,4) << endl;
    

    return 0;
}