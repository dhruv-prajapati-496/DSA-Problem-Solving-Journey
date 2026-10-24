//Delete the First and Last Node
//Create a singly linked list manually using your own Node and List classes.
//Read n integers and insert them at the end. Then perform the following operations in order:
//1. Delete the first node.
//2. Delete the last node from the remaining list.
//3. Print the resulting Linked List.
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
        if(head ==NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }   
    }
    
    void pop_back(){
        if(head == NULL){
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        temp -> next = NULL;
        tail = temp;
    }
    
    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head -> next;
        if(head == NULL) tail = NULL;
        temp -> next = NULL;
        delete temp;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp -> next;
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
    cout<<"Enter Size of Linked List: ";
    int n; cin>>n;
    cout<<"Enter Elements: ";
    List myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }

    // Removing First Element
    myList.pop_front();
    
    // Removing Last Element
    myList.pop_back();

    // Printing Linked List
    cout<<"Result: "<<endl;
    myList.print();

    return 0;
}