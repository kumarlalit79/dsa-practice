#include<iostream>
using namespace std;

bool isPresent(int arr[][4] , int target, int row , int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
            
        }
        
    }
    return 0;
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

    int target;
    cout << "Target = ";
    cin >> target;

    if (isPresent(arr,target,3,4))//yaha pe 3,4 means 3 row and 4 column. array ki dimensions hai
    {
        cout << "Element Found" << endl;
    }
    else{
        cout << "Element not Found" << endl;
    }


    return 0;
}