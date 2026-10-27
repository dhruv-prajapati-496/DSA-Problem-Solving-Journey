// Delete all occurences of a value.
/*
Create a singly linked list manually, containing n integers.

Given a target value k, delete every node whose data equals k.

Preserve the relative order of all remaining nodes and print the final Linked List.
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
        tail -> next = newNode;
        tail = newNode;
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;  
        } cout<<"NULL"<<endl;
    }
    void deleteAllOccurencesOfAValue(int val){
        while(head != NULL && head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        if(head == NULL){
            tail = NULL;
            return;
        }

        Node* curr = head;
        while(curr->next!= NULL){
            if(curr -> next -> data == val){
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        } tail = curr;

    }
    ~List(){
        Node* temp = head;
        while(temp != nullptr){
            Node* nextNode = temp -> next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }
    
};
int main(){
    cout<<"Enter No. of Elements: "; 
    int n; cin>>n; 
    if(n<0){
        cout<<"Invalid Input";
        return 0;
    }

    cout<<"Enter Elements\n";
    List myList;
    for(int i = 0; i<n ; i++){
        int val; cin>>val;
        myList.push_back(val);
    }


    cout<<"Enter Key: ";
    int k; cin>>k;
    myList.deleteAllOccurencesOfAValue(k);
    cout<<"Linked List: \n";
    myList.printLL();
    return 0;
}