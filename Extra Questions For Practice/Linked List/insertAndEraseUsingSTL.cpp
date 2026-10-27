// Insert and Erase Using STL
/*
Create a C++ STL list<int> containing n integers.

Perform these operations in order:
1. Insert integer x immediately before the element at 0-based index p.
2. Delete the element at 0-based index q in the updated list.
3. Print the final list and its size.
*/
#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main(){
    cout<<"Enter Linked List Size: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input: ";
        return 0;
    }
    if(n>0) cout<<"Enter Elements: ";
    list<int> myList;
    for(int i = 0; i<n; i++){
        int val; cin>>val;
        myList.push_back(val);
    }
    cout<<"Enter Value of P: ";
    int p; cin>>p;
    if(p<0 || p>n){
        cout<<"Invalid Input";
        return 0;
    }
    //iterator declaration
    list <int>::iterator it = myList.begin();
    advance(it,p);
    cout<<"Enter Value of X: ";
    int x; cin>>x;
    myList.insert(it,x);
    cout<<"Enter Value of Q: ";
    int q; cin>>q;
    if(q<0 || q >= n+1){
        cout<<"Invalid Input";
        return 0;
    }
    list<int>::iterator it2 = myList.begin();
    advance(it2,q);
    myList.erase(it2);
    cout<<"Result:\n";
    for(const int &i : myList){
        cout<<i<<" ";
    } cout<<"\nSize = "<<myList.size();
    
    return 0;
}