#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target){
    int row = arr.size();
    int col = arr[0].size();

    int start = 0;
    int end = row*col-1;

    int mid = start + (end-start)/2;

    while (start <= end)
    {
        int element = arr[mid/col][mid%col]; // row number nikaal liya

        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return 0;

}


int main(){

    vector<vector<int>> arr(3, vector<int>(4));

    cout << "Enter the elements of 3x4 matrix:\n";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];

    cout << "\nMatrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "Enter target : " ;
    int target;
    cin >> target;
    

    bool result = searchMatrix(arr , target);  
    if (result)
    {
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    

    return 0;
}

/*
    1 3 5 7 
    10 11 16 20
    23 30 34 60
*/