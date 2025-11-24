#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> arr){

    vector<int> ans;
    int row = arr.size();// number of rows nikaal li
    int col = arr[0].size(); // kisi bhi ek row ka size nikaal lena

    int count = 0; // number of element print krne ke liye
    int total = row * col; // total no of element = row*col; we know it from matrix property

    // index initilization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while (count < total)
    {
        // printing statring row
        for(int index = startingCol; index <= endingCol; index++){
            if (count >= total) 
                break; // taki extra elements push na ho
            ans.push_back(arr[startingRow][index]); 
            count++; // jab bhi koi element add/print krna ho to count badhana tha   
        }
        startingRow++; // starting row ko agli row pe point kr diya


        // printing ending col
        for (int index = startingRow; index <= endingRow; index++)
        {
            if (count >= total) break; 
            ans.push_back(arr[index][endingCol]); 
            count++;
        }
        endingCol--;

        // printing ending row
        for (int index = endingCol; index >= startingCol; index--)
        {
            if (count >= total) break; 
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;

        // print starting col
        for (int index = endingRow; index >= startingRow; index--)
        {
            if (count >= total) break; 
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}


int main(){

    vector<vector<int>> arr(3, vector<int>(3));

    cout << "Enter the elements of 3x3 matrix:\n";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    cout << "\nMatrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "\nSpiral Print:\n";

    vector<int> result = spiralOrder(arr);   // return lo

    // print the spiral result
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}
