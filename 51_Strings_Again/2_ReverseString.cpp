#include<iostream>
#include<cstring>
using namespace std;

void reverseString(char str[] , int size){
    
    int s = 0;
    int e = size - 1;

    while (s < e)
    {
        swap(str[s] , str[e]);
        s++;
        e--;
    }
}

int main(){
    
    char str[20] = "Babbar";

    int size = strlen(str);  // string length nikaal li with import krke. tum custom function bhi likh skte 1st question ki trh

    cout << "Original: " << str << endl;

    reverseString(str , size);

    cout << "Reversed: " << str << endl;

    return 0;
}
