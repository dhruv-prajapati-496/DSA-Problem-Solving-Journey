/*
Find the Middle Node of a Linked List

Create a singly linked list manually.

Find and print the value of its middle node.

If there are two middle nodes (an even number of nodes), return the second middle node.
Example 1 — Odd length */
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
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        } cout<<"NULL";
    }
    Node* getHead(){
        return head;
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
Node* middleOfTheLinkedList(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    cout<<"Enter Number of Elements: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input";
        return 0;
    }
    if(n!=0) cout<<"Enter Elements: ";
    if(n==0){
        cout<<"Empty List";
        return 0;
    }
    List myList;
    for(int i = 0; i<n ; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    Node* ans = middleOfTheLinkedList(myList.getHead());
    if(ans != NULL)
    cout<<"The middle of The Linked List is: "<<ans->data;
    return 0;   
    // I know we can also solve this by using n, but n is just an input to ensure the size of the linked list. maybe later if the list is modified then we have to use slow fast pointer approach to get the middle
}