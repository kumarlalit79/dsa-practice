#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<int> lower(26, 0);
    vector<int> upper(26, 0);

    // Count frequency
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upper[s[i] - 'A']++;
        }
    }

    int count = 0;
    bool odd = 0;

    for (int i = 0; i < 26; i++) {
        // lower
        if (lower[i] % 2 == 0) 
            count += lower[i];
        else { 
            count += lower[i] - 1; 
            odd = 1; 
        }

        // upper 
        if (upper[i] % 2 == 0) 
            count += upper[i];
        else { 
            count += upper[i] - 1; 
            odd = 1; 
        }
    }

    cout << "Longest palindrome length: " << count + odd;
    return 0;
}
