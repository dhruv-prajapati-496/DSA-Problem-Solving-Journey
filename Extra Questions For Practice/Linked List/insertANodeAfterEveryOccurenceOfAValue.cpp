/*
Insert a Node After Every Occurrence of a Value
Given a singly linked list, an integer target, 
and an integer newValue, insert a new node containing newValue immediately after every node whose original value equals target.
Keep the existing nodes in their original order.
Only the original nodes should trigger insertions. Newly inserted nodes must not trigger further insertions.
Constraints: 0 ≤ number of nodes ≤ 100000. Node values, target, and newValue are integers.
Requirements: O(n) time, O(1) extra working space excluding the newly allocated nodes. Do not convert the linked list into a vector or use std::list; use your manually implemented Node structure.
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
    void insertANodeAfterEveryOccurenceOfANode(int val, int tar){
        Node* temp = head;

        while(temp!=NULL){
            if(temp->data == tar){
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                if(newNode->next == NULL){
                    tail = newNode;
                }
                temp = newNode->next;
            }
            else{
                temp = temp->next;
            }
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
    cout<<"Enter Linked List Elements: ";
    List myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"Enter Target: ";
    int tar; cin>>tar;
    cout<<"Enter Value: ";
    int val; cin>>val;
    cout<<"Input List: \n";
    myList.printLL();
    myList.insertANodeAfterEveryOccurenceOfANode(val,tar);
    cout<<"\nOutputList: \n";
    myList.printLL();
    return 0;
}