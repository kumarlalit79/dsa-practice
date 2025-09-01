#include<iostream>
using namespace std;

int main(){
    // char arr[] = {'a','b','c','d'};
    //  cout << arr;
    // for(int i=0; i<=4; i++){
    //     cout << arr[i];
    // }

    // char arr[10];
    // cin >> arr;
    // cout << arr;

    // char arr[10];
    // cin >> arr;
    // arr[2] = '\0';
    // cout << arr;

    // string s;
    // cin >> s;
    // cout << s;
    
    // string s;
    // getline(cin, s);
    // cout << s;

    // string s;
    // cin >> s;
    // cout << s.size();

    // string s1 = "\\0";
    // cout << s1;

    // reverse
    // string s1 = "Lalit";
    // int start = 0;
    // int end = s1.size() -1;
    // while (start < end)
    // {
    //     swap(s1[start] , s1[end]);
    //     start++,end--;
    // }
    // cout << s1;

    // find size
    // string s1 = "Lalit";
    // int size = 0;
    // while (s1[size] != '\0')
    // {
    //     size++;
    // }
    // cout << size;

    // check palindrome
    string s ;
    cin >> s;
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            cout << "It is not a palindrome";
            return 0;
        }
        start++,end--;
        
    }
    cout << "It is a palindrome";
}