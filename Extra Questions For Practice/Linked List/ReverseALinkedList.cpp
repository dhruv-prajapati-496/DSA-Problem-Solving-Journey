// How to Reverse a Linked List ?
#include<iostream>
using namespace std;
// Node Class
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
    void push_front(int val){           //O(1)
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
    void push_back(int val){            //O(1)
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }

    }

    void pop_front(){                   //O(1)
        if(head == NULL){
            cout<<"List is Empty\n";
            return;
        }
        Node* temp = head;
        head = head -> next;
        if(head == NULL) tail = NULL;
        temp -> next = NULL;
        delete temp;
    }

    void pop_back(){                    //O(n)
        if(head == NULL){
            cout<<"List is Empty: \n";
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while( temp -> next != tail){
            temp = temp->next;
        }
        delete tail;
        temp -> next = NULL;
        tail = temp;
    }

    void insert(int val, int pos){      //O(n)
        if(pos<0){
            cout<<"Invalid Position\n";
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i<pos-1; i++){
            if(temp == NULL){
                cout<<"Invalid Position\n";
                return;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp -> next;
        temp -> next = newNode;
    }

    void printLL(){                     //O(n)
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp -> data<<" -> ";
            temp = temp -> next;
        } cout<<"NULL"<<endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        tail = head; 

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev; 
    }

    int search(int key){                //O(n)
        Node* temp = head; 
        int idx = 0;
        while(temp != NULL){
            if(temp -> data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;

    }
};
int main(){
    cout<<"Enter Linked List Size: ";
    int n; cin>>n;
    cout<<"Enter Values in the Linked list: ";
    List mylist;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        mylist.push_back(val);
    }
    mylist.printLL();
    cout<<"Reverse the Linked List: ";
    mylist.reverse();
    mylist.printLL();
    return 0;
}