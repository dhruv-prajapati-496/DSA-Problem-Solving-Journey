/*
Insert A node at a given position
Create a singly linked list manually using your own Node and List classes.

Read n integers and build the list. Then read an integer x and a 0-based position pos.

Insert a new node containing x at index pos, shifting the existing nodes one position forward.
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

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void insert(int val, int pos){
        if(pos<0){
            cout<<"Invalid Position\n";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i<pos -1; i++){
            if(temp == NULL){
                cout<<"Invalid Position\n";
                return;
            }
            temp = temp ->next;
        }
        Node* newNode = new Node(val);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        if(newNode -> next == NULL){
            tail = newNode;
        }
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    ~List(){
        Node* temp = head;
        while(temp!= nullptr){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }
};
int main(){
    cout<<"Enter Number of Elements: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input\n";
        return 0;
    }
    if(n!=0)
    cout<<"Enter Elements: ";
    List myList;
    for(int i = 0; i<n ; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"Enter Value to Insert: ";
    int k,pos; cin>>k;
    cout<<"Enter position: "; cin>>pos;
    myList.insert(k,pos);
    cout<<"Result: \n";
    myList.printLL();
    return 0;
}