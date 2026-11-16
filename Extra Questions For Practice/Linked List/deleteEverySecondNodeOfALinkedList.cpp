/*
Delete Every Second Node of a Linked List
Create your own Node structure and List class using pointers. Maintain both head and tail.
Given a singly linked list, delete every node at an even position (2nd, 4th, 6th, ...). Positions are 1-based.
You must actually delete the unwanted nodes from memory, not merely skip them while printing.
Constraints: 0 ≤ number of nodes ≤ 100000. Node values can be any 32-bit signed integers.
Requirements
- Manually create Node and List using new and pointers.
- Do not use std::list, vector, or any other STL container to solve the problem.
- O(n) time and O(1) auxiliary space.
- Correctly update head and tail.
- Use delete to free each removed node.
- Include a destructor to free any nodes remaining when the list is destroyed.
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

    void printLL(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    void solution(){
        Node* temp = head;

        while(temp!=NULL && temp->next != NULL){
            Node* toDelete = temp->next;
                temp->next = toDelete->next;
                if(toDelete==tail) tail = temp;
                toDelete ->next = NULL;
                delete toDelete;
                temp = temp->next;
        }
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
    if(n>0) cout<<"Enter Linked List Elements:\n";
    List myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"List Before Deletion: \n";
    myList.printLL();
    cout<<"\nList After Deletion: \n";
    myList.solution();
    myList.printLL();
    return 0;
}