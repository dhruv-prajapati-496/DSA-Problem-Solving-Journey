/*
Count Nodes Greater Than a Given Value
Create a singly linked list manually using your Node and List classes.

Given an integer target, traverse the linked list and count how many nodes contain values strictly greater than target.

Also calculate the sum of those qualifying node values.

Do not modify the linked list.
*/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head = tail = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail ->next = newNode;
            tail = newNode;
        }
    }
    void countNodesGreaterThanAGivenValue(int tar, int &count, long long &sum){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data > tar){
                count++;
                sum += temp->data;
            }
            temp = temp->next;
        }
    }
    ~List(){
        Node* temp = head;
        while(temp != nullptr){
            Node* nextNode = temp ->next;
            delete temp;
            temp = nextNode;
        } 
        head = tail = nullptr;
    }
};
int main(){
    cout<<"Enter size of Linked List: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input";
        return 0;
    }
    if(n!=0)
    cout<<"Enter Elements: ";
    List myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"Enter Target: ";
    int tar; cin>>tar;
    long long sum = 0; int count = 0;
    myList.countNodesGreaterThanAGivenValue(tar, count, sum);
    cout<<"Count = "<<count<<endl;
    cout<<"Sum = "<<sum<<endl;
    return 0;   
}