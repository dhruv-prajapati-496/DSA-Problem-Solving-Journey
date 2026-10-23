// Insert at Beginning and End Using STL
//Use C++ STL list<int> to create a list initially containing n integers.
//Then perform two operations in this exact order:
//1. Insert integer x at the beginning.
//2. Insert integer y at the end.
//Finally, print the list from beginning to end and its total number of elements.
#include<iostream>
#include<list>
using namespace std;
int main(){
    cout<<"Enter Linked List Size: ";
    int n; cin>>n;
    cout<<"Enter Elements in Linked List: ";
    list<int> ll;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        ll.push_back(val);
    }
    cout<<"Insert Integer X at the beginning: ";
    int x; cin>>x; ll.push_front(x);
    cout<<"Insert Integer Y at the end: ";
    int y; cin>>y; ll.push_back(y);
    cout<<"Linked List Elements: [ ";
    for(const int& val: ll){
        cout<<val<<" ";
    } cout<<"]"<<endl;
    cout<<"Size: "<<ll.size();
    return 0;
}