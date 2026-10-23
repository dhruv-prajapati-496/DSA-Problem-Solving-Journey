//Create and Traverse a Singly Linked List
//Create a singly linked list manually using a Node class or structure.
//Read n integers and insert them at the end of the list, preserving their input order.
//Then traverse the list and print all the elements.
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
class List {
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
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void printLL(){
        Node* temp = head;
        cout<<"[ ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp -> next;
        }
        cout<<"]";
    }           // Calling Destructor to free up the allocated memory.
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
    cout<<"Enter Elements in linked List: ";
    List ll;
    for(int i = 0; i<n; i++){
        int el; 
        cin>>el;
        ll.push_back(el);
    }
    cout<<"Linked List Elements are: ";
    ll.printLL();
    return 0;
}