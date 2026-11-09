/*
Remove Duplicates from a Sorted Linked List
Problem Statement
You are given the head of a sorted singly linked list (non-decreasing order). Remove all duplicate nodes so that each distinct value appears only once. Return the head of the modified list.
You must modify the list in place by changing pointers — do not create a new list.
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

    void removeDuplicates(){
        if (head == NULL) return;
        Node* curr = head;
        while(curr!=NULL && curr->next != NULL){
            if(curr->data == curr->next->data){
                Node* duplicate = curr -> next;
                curr->next = duplicate -> next;
                if(duplicate==tail) tail = curr;
                delete duplicate;
            } else{
                curr = curr->next;
            }
        }
        if(head == NULL){
            tail = NULL;
        } else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp->next;
            }
            tail = temp;
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    ~List(){
        Node* temp = head;
        while(temp != nullptr){
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
    cout<<"Enter Elements: ";
    List myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"Original List: \n";
    myList.printLL();
    myList.removeDuplicates();
    cout<<"Output: \n";
    myList.printLL();
    return 0;
}