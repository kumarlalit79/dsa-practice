#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    vector<string>ans(10); 
    string temp;
    int count = 0 , index = 0;
    while (index < s.size())
    {
        if (s[index] == ' ')
        {
            int position = temp[temp.size() - 1] - '0';
            temp.pop_back();
            ans[position] = temp;            
            temp.clear();
            count++;
        }
        else{
            temp += s[index];                
        }
        index++;
    }
    // last mai jo word likha hoga usko alg se handle karna padega
    int position = temp[temp.size() - 1] - '0';
    temp.pop_back();
    ans[position] = temp;            
    temp.clear();
    count++;
    
    // accessing
    for (int i = 0; i < count; i++)
    {
        temp += ans[i];
        temp += ' ';
    }
    temp.pop_back();
    cout << temp;
    return 0;
}