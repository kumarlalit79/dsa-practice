#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr , int n , int m , int mid){

    int studentCount = 1; // pehle student ke liye start kiya hamesha
    int pageSum = 0; // like 10+20, ese krke ham sub nikaal re the fir mid se compare kr re the wo h ye
    
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i]; // normally add kardo
        }
        else{
            studentCount++;
            if (studentCount > m || arr[i]>mid) // check karo ki kahi student count jayada to nahi ho gaya
            {
                return false;
            }
            pageSum = arr[i]; 
        }
    }
    return true;
}

int allocateBooks(vector<int> arr , int n , int m){
    int s = 0;

    // end mai sabka sum lena hai, to loop se hoga wo
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    
    int e = sum;
    int ans = -1;

    int mid = s +  (e-s) / 2;

    while (s <= e)
    {
        if(isPossible(arr , n , m , mid)){
            // possible solution hota hai to ans mai store krte and e=mid-1
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid + 1;
        }
        mid = s +  (e-s) / 2;
    }
    return ans;
}

int main(){

    vector<int> arr = {10,20,30,40};
    int n = 4;
    int m = 2;
    cout << "Minimum answer : " << allocateBooks(arr , n , m);
        
    return 0;
}