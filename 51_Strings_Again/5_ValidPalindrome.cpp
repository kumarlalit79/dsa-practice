#include<iostream>
using namespace std;

// faltu character hata re
bool valid(char ch){
    // FIXED: '0' && '1' -> '0' && '9'
    if ((ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z') || 
        (ch >= '0' && ch <= '9')) // agr inme se kuch h to valid hai
    {
        return 1;
    }
    return 0;
}

// lower case mai kardo
char toLowerCase(char ch){
    if ((ch >='a' && ch <='z') || (ch >='0' && ch <='9'))
    {
        return ch;
    }
    else{
        // capital ko small mai convert kar re
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// FIXED: correct parameter type string str[]
bool checkPalindrome(string &str){
    int s = 0;
    int e = str.length()-1;

    while (s<=e)
    {
        if (str[s] != str[e])    // characters match nahi hue
        {
            return 0;
        }
        else{
            s++;    // aage badho
            e--;    // peeche aaao
        }
    }
    return 1;
}


bool validPalindrome(string s){
    
    string temp = ""; // new string mai daal denge valid character ko

    // STEP 1: valid characters collect karna
    for (int j = 0; j < s.length(); j++)
    {
        if (valid(s[j]))
        {
            temp.push_back(s[j]);  // valid character add kar diya
        }
    }

    // STEP 2: lowercase mai convert karna
    // FIXED: `i < temp.length()` was wrong
    for (int j = 0; j < temp.length(); j++)
    {
        temp[j] = toLowerCase(temp[j]);
    }

    // STEP 3: final palindrome check
    return checkPalindrome(temp);
}

int main(){
    
    char str[100];   // size badha diya safety ke liye
    cout << "Enter string : " << endl;
    cin.getline(str, 100);  // getline for spaces also

    // converting char array -> string
    string s = str;

    int check = validPalindrome(s);

    if (check)
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}

/*
    test case : A man, a plan, a canal: panama - true
    race a car - false
*/