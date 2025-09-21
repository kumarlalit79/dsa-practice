#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


vector<long long> printFirstNegativeInteger(long long int A[] , long long int N, long long int K){
    
    deque<long long int> dq;
    vector<long long> ans;

    // process karo first window of K size
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0) // agr mera current element < 0 hai to uske queue mai store karna hai
        {
            dq.push_back(i);
        }
        // yaha tk first element process hogya
    }
     
    // ab answer nikaal lo of first k size window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else{
        // koi element pada hi nahi hai
        ans.push_back(0);
    }

    // baaki windows ko bhi check karo yrr
    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i-dq.front() >= K) // that means aap current K size ke bahar ke hai, aapko hatana padega
        {
            dq.pop_front();
        }

        // addition
        if (A[i] < 0) // agr curr element -ve number hai
        {
            dq.push_back(i);
        }
        
        // answer store karwa lo
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else{
            // koi element pada hi nahi hai
            ans.push_back(0);
        }
    }

    return ans;
}

int main(){

    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = 8;
    long long int K = 3;

    vector<long long> result = printFirstNegativeInteger(A, N, K);

    cout << "First negative in every window: ";
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
