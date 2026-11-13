/*
Reverse a Singly linked list
Problem Statement
Add a member function void reverse() to your List class that reverses the linked list in place by changing next pointers. 
After calling reverse(), head must point to what was the last node, and tail must point to what was the first node.
Within O(n) time & O(1) space.
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
        } else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void reverse(){

        if(head == NULL || head->next == NULL) return;

        Node* prev = NULL;
        Node* curr = head;
        tail = head;

        while(curr!=NULL){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        } head = prev;
    }

    void PrintLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    ~List(){
        Node* temp = head;
        while(temp!=nullptr){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } head = tail = nullptr;
    } 
};
int main(){
    cout<<"Enter Linked List Size: ";
    int n; cin>>n;
    if(n>0) cout<<"Enter Linked List Elements: ";
    List myList; 
    for(int i = 0; i<n ; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"\nBefore Reverse: \n";
    myList.PrintLL();
    cout<<"\nAfter Reverse: \n";
    myList.reverse();
    myList.PrintLL();
    return 0;
}