#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

#define MAX 100

// peeche ye function values ke aadhar pe likha tha, ab ye index ke hisab se likhna hoga
vector<int> nextSmallerElement(int* arr, int n){

    stack<int> s;
    s.push(-1); 

    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) // yaha value ko value se compare karo
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i); // value ki jgh yaha index push karo
    }
    return ans;
}

vector<int> prevSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1); 

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) // yaha value ko value se compare karo
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i); // value ki jgh yaha index push karo
    }
    return ans;
}

int largestRectangleArea(int* height, int n){


    vector<int> next(n); 
    next = nextSmallerElement(height , n); 

    vector<int> prev(n); 
    prev = prevSmallerElement(height , n); 

    int maxArea  = INT_MIN;

    for(int i=0; i<n; i++){
        // yaha area calculate kr lunga
        int length = height[i];
        
        
        // handling width = -1 case. If no next smaller element exists, treat it as n (out of bound index)
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int breadth = next[i] - prev[i] - 1;
        int newArea = length * breadth;
        maxArea  = max(maxArea  , newArea); 
    }
    return maxArea;

}

int maxAreaInMatrix(int M[MAX][MAX], int n, int m){

    // step 1 : pehli row ke liye answer nikaal lo
    int area = largestRectangleArea(M[0] , m); // pehle row pass kardi hai - M[0] and m = no of columns
     
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update karo previous row ke element ko add karke
            if (M[i][j] != 0) // 0 0 na present ho
            {
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{ // agr 0 0  present ho to waha bar nahi banate 0 hi daal dete hai
                M[i][j] = 0;
            }
        }
        // is loop se bahar nikalne par entire row update ho chuki hogi
        area = max(area, largestRectangleArea(M[i],m));
    }
    return area;
}

int main() {
    int n = 4, m = 4;
    int M[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << "Maximum Area of Rectangle in Binary Matrix: " << maxAreaInMatrix(M, n, m) << endl;

    return 0;
}