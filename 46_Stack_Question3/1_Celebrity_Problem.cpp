#include<iostream>
#include<stack>
#include<vector>
using namespace std;


bool knows(vector<vector<int>> &M , int A, int B){

    if (M[A][B] == 1)
    {
        return true;
    }
    else{
        return false;
    }

}

int celebrity(vector<vector<int>> &M , int n){ // 2D array banaya hai
    stack<int> s;

    // step 1 : saare element stack ke andr push karne hai
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step 2 : do bande nikaal do, and unhe compare karlo
    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();

        int B = s.top();
        s.pop();

        if (knows(M,A,B))
        {
            // A ko discard and B ko push
            s.push(B);
        }
        else{
            s.push(A);
        }
    }

    int potentialCandidate = s.top(); // potential candidate ko store karwa liya

    // step 3 : jab stack mai single element bacha hoga, wo potential celebrity hoga, jarrori nahi ki wo hi celebrity ho , ho bhi skta and nahi bhi, to use verify karlo
    bool rowCheck = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[potentialCandidate][i] == 0) // agr row ke andr saare ke saare 0 hai , to rowcheck ko true mark kar diya
        {
            zeroCount++;
        }
        
    }
    
    // check karna hai ki kya saare 0 hai
    if (zeroCount == n)
    {
        rowCheck = true;
    }
    
    // ab column check karlo
    bool colCheck = false;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][potentialCandidate] == 1)// agr col ke andr saare ke saare 1 hai , to colcheck ko true mark kar diya
        {
            oneCount++;
        }
        
    }

    // saare element 1 hone chahhiye except diagonal waala
    if (oneCount == n-1)
    {
        colCheck = true;
    }
    
    if (rowCheck == true && colCheck == true)
    {
        return potentialCandidate;
    }
    else{
        return -1;
    }
}

int main() {
    // Example matrix:
    // Person 0 knows 1 and 2
    // Person 1 knows nobody (possible celebrity)
    // Person 2 knows 1
    vector<vector<int>> M = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();
    int result = celebrity(M, n);

    if (result == -1)
        cout << "No Celebrity Found" << endl;
    else
        cout << "Celebrity is Person " << result << endl;

    return 0;
}