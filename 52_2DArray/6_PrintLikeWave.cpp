#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr , int nRows, int mCol){

    vector<int> ans;

    // for loop for column
    for (int col = 0; col < mCol; col++)
    {
        // ab check krna hai even h ya odd, us hisaab se top bottom jaunga
        if (col & 1)
        {
            // odd case - bottom to top
            for (int row = nRows-1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
                ans.push_back(arr[row][col]);
            }
            
        }
        else{
            // 0 or even index - top to bottom
            for(int row = 0; row<nRows; row++){
                cout << arr[row][col] << " ";
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}


int main(){

    vector<vector<int>> arr(3, vector<int>(4));

    cout << "Enter the elements of 3x4 matrix:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "\nMatrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nWave Print:\n";
    wavePrint(arr, 3, 4);

    return 0;
}