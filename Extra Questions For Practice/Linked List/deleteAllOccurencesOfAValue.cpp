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
    
};