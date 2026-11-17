/*
Delete the First Occurrence of a Target in a Linked List
Create your own Node structure and List class using pointers. Maintain both head and tail.
Given a singly linked list and an integer target, delete only the first node whose data equals target.
If the target does not exist, leave the list unchanged.
You must free the deleted node's memory using delete.
Constraints: 0 ≤ number of nodes ≤ 100000. Node values and target are 32-bit signed integers.
Requirements: O(n) time, O(1) auxiliary space, manually allocated nodes, correct head and tail updates, 
and a destructor for remaining nodes. Do not use std::list, vector, or another STL container to implement the linked list.
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
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFirstOccurenceOfAElement(int tar){
        if(head == NULL) return;
        if(head->data == tar){
            Node* toDelete = head;
            head = head->next;
            if(head == NULL){
                tail = NULL;
            }
            delete toDelete;
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->data == tar){
                Node* toDelete = temp->next;
                temp->next = toDelete->next;
                if(toDelete==tail){
                    tail = temp;
                }
                toDelete->next = NULL;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    void printLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    ~List(){
        Node* temp = head;
        while(temp!=nullptr){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }
};
int main(){
    cout<<"Enter Linked List Size: ";
    int n; cin>>n;
    if(n>0) cout<<"Enter Linked List Elements: ";
    List myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"Enter target: ";
    int tar; cin>>tar;
    myList.deleteFirstOccurenceOfAElement(tar);
    myList.printLL();
    return 0;
}