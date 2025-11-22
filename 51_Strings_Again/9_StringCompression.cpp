#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char> &chars){
    int i = 0; // for traversing the entire vector
    int ansIndex = 0; // cuz new array nahi lena, same arry mai store karwana, tracking purpose ke liye h
    int n = chars.size();

    while (i<n)
    {
        int j = i+1; // i se agla element utha liya, cuz agle se compare karwana hai
        while(j<n && chars[i] == chars[j]){ // har character ko aage waale se compare krna, same hai to ++ krdo , and diff hai to ruk jao and use char arrray ke andr daal do and compare karwao
            j++;
        }

        // loop ke bahar - means vector poora traverse kar liya , ya fir new/different character encounter kia
        chars[ansIndex++] = chars[i];// old char  store karlo

        // ab count store karlo old ka
        int count = j-i;

        if (count > 1)
        {
            // converting counting into single digit and saving in answer
            string cnt = to_string(count); 
            for(char ch : cnt){
                chars[ansIndex++] = ch;
            }
        }
        // ab mai agle character pe ja skta, or agla betha hai j pe. moving to new character
        i = j;
    }
    return ansIndex;
}

int main(){
    
    vector<char> ch = {'a','a','b','b','b','c','c','c'};
    int size = compress(ch);

    for(int i=0; i<size; i++){
        cout << ch[i] << " ";
    }

    
    return 0;
}