#include<iostream>
#include<array>
using namespace std;

int main(){

    // Normal Array
    int normal_arr[3] = {1,2,3};

    // STL Array
    array<int,4> stl_array = {1,2,3,4};

    // Size nikaal re
    int size = stl_array.size();

    // traversing
    for (int i = 0; i < size; i++)
    {
        cout << stl_array[i] << " " << endl;
    }

    // At
    cout << "Elements at 2nd index: " << stl_array.at(2) << endl;

    // Checking empty array
    cout << "Empty or Not : " << stl_array.empty() << endl;
    
    // Finding first and last element from STL Array
    cout << "First Element : " << stl_array.front() << endl;
    cout << "Last Element : " << stl_array.back() << endl;
}