#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target){
    int row = arr.size();
    int col = arr[0].size();

    int rowIndex = 0;
    int colIndex = col-1; //first row ke last element se

    while (rowIndex < row && colIndex >=0)
    {
        int element = arr[rowIndex][colIndex]; 

        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            rowIndex++;
        }
        else{
            colIndex--;
        }
        
    }
    return 0;

}


int main(){

    vector<vector<int>> arr(5, vector<int>(5));

    cout << "Enter the elements of 5x5 matrix:\n";

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    cout << "\nMatrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
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
    1 4 7 11 15
    2 5 8 12 19
    3 6 9 16 22
    10 13 14 17 24
    18 21 23 26 30
*/