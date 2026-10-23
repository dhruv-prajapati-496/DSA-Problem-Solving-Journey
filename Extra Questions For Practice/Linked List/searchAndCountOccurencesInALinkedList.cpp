// Search and count occurences in a linked list.
//Create a singly linked list containing n integers.
//Given a target value k, traverse the linked list and determine:
//- Whether k exists in the list.
//- How many times k appears.
//- The position of its first occurrence, using 0-based indexing.
//If the target is absent, its first position should be -1.
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
    void searchTarget(int k){
        Node* temp = head;
        int firstOccurence = -1, count = 0;
        int index = 0;
        while(temp != NULL){
            if(temp ->data == k){
                if(count == 0){
                    firstOccurence = index;
                }
                count ++;
            }
            index++;
            temp = temp->next;
        }
        cout<<"Found: "<<( count > 0 ? "True" : "False")<<endl;
            cout<<"Count = "<<count<<endl;
            cout<<"First Position = "<<firstOccurence;
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
    if(n>0) cout<<"Enter Linked List Elements: ";
    List ll;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        ll.push_back(val);
    }
    cout<<"Enter Target Value: ";
    int k; cin>>k;
    ll.searchTarget(k);
    return 0;
}