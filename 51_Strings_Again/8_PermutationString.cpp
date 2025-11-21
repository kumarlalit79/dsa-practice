#include<iostream>
using namespace std;

bool checkEqual(int a[26] , int b[26]){
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }   
    }
    return 1;
}



bool checkInclusion(string s1, string s2) {

    // agar s1 badi string hai to permutation kabhi nahi ban sakti
    if (s1.length() > s2.length()) 
        return false;

    // -----------------------------
    // Step 1: s1 ke characters ka frequency count banao
    // -----------------------------
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++) {   // using your FOR loop
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // -----------------------------
    // Step 2: s2 ki first window ka count banao
    // -----------------------------
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    // ❌ Your condition was wrong:
    // while (i < windowSize && s2.length()) — s2.length() always true
    // ✔ Fix:
    while (i < windowSize) {   // using your WHILE loop
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // first window check
    if (checkEqual(count1, count2))
        return true;

    // -----------------------------
    // Step 3: Slide window (using WHILE loop as you wrote)
    // -----------------------------
    while (i < s2.length()) {

        // new character add karo
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        // old character remove karo
        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        i++;

        // check if match occurs
        if (checkEqual(count1, count2))
            return true;
    }

    // agar kahin match nahi mila
    return false;
}


int main(){
    
    string s1 = "ab";
    string s2 = "eidbaooo";

    bool check = checkInclusion(s1, s2);

    if (check) cout << "True";
    else cout << "False";
    
    return 0;
}


/*
    s1 = "ab"
    s2 = "eidbaooo"
    True

    Test Case 2
    s1 = "ab"
    s2 = "eidboaoo"
    Output: False

    Test Case 3
    s1 = "adc"
    s2 = "dcda"
    Output: True


    Test Case 4
    s1 = "hello"
    s2 = "ooolleoooleh"
    Output: False
*/