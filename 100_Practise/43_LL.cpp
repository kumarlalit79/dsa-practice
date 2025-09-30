#include<iostream>
#include<vector>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int _data){
        this->data = _data;
        this->next = NULL;
    }

};

void insertAtTail(Node* &tail, int data){

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

bool checkPalindrome(vector<int> arr){

    int size = arr.size();
    int i = 0;
    int j = size - 1;

    while (i <= j)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

bool isPalindrome(Node* &head){
    if (head == NULL && head -> next == NULL)
    {
        return false;
    }
    
    Node* temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkPalindrome(arr);
}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);

    print(head);
    
    bool check = isPalindrome(head);
    if (check)
    {
        cout << "yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}