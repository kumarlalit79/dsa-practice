#include<iostream>
#include<vector>    
#include<algorithm>    
using namespace std;

bool isPossible(vector<int> &stalls, int k , int mid){

    int cowCount = 1; // suppose pehle cow ke liye process kr ra
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            // is case mai place kardo
            cowCount++;    
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;    
}

int aggressiveCow(vector<int> &stalls, int k){
    
    // sabse pehle array ko sort krlo
    sort(stalls.begin() , stalls.end());
    
    int s = 0;
    int maxi = -1;

    for (int i = 0; i < stalls.size(); i++) 
    {
        maxi = max(maxi,stalls[i]); // maximum value nikaal li
    }
    
    int e = maxi;
    
    int ans = -1;

    int mid = s + (e-s) / 2;

    while (s <= e)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
    return ans;
}

int main(){

    vector<int> stalls = {4,2,1,3,6};
    int k = 2;
    cout << "Result : " << aggressiveCow(stalls, k);
        
    return 0;
}