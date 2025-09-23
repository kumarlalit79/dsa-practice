#include <iostream>
#include<queue>
using namespace std;

int solve(int *arr, int size , int k){

    deque<int> maxi(k);
    deque<int> mini(k);

    // addition of first k size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while ( !mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // saari window ko check karo
    int ans = 0;
    for (int i = k; i < size; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        // next window mai chalte hai - yaha addition and removal karna hota hai

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition - same upper ke for loop ka copy past krdo
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while ( !mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

    }

    // make sure to consider last waali window
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}

int main(){

    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout << solve(arr,7,k) << endl; // answer = 18
    
    return 0;
}