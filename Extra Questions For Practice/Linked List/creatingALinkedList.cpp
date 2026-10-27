// This Code contains the complete implementation of a Linked list.
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
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void printLL(){                     //O(n)
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp -> data<<" -> ";
            temp = temp -> next;
        } cout<<"NULL"<<endl;
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
    //Creating A linked list named ll.
    List ll;
    // adding values to the Linked List.
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    cout<<"Printing The Created Linked List: ";
    ll.printLL();

    cout<<"Push Back: 4\n";
    ll.push_back(4);
    ll.printLL();

    cout<<"Pop Front: \n";
    ll.pop_front();
    ll.printLL();

    cout<<"Push Front: 7\n";
    ll.push_front(7);
    ll.printLL();

    cout<<"Pop Back: \n";
    ll.pop_back();
    ll.printLL();

    cout<<"Insert 5 at position 2\n";
    ll.insert(5,2);
    ll.printLL();

    cout<<"Searching index of 5 \n";
    cout<<"Index of 5 is: "<<ll.search(5);

    return 0;
}