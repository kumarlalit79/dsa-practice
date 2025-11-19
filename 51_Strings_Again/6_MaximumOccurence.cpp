#include<iostream>
using namespace std;

char getMaxOccChar(string s){
    int arr[26] = {0};

    // array ka count nikaal re
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z') // that means lowercase mai hoga
        {
            number = ch - 'a';
        }
        else{ // that means uppercase mai hoga
            number = ch - 'A';
        }
        arr[number]++;
    }

    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
        
    }

    char finalAns = 'a' + ans;
    return finalAns;
    
}

int main(){
    
    string s;
    cout << "Enter string : " << endl;
    cin >> s;

    cout << getMaxOccChar(s);

    return 0;
}

