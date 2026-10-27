/*
Remove All Even Numbers Using STL
Given an STL list<int> containing n integers, remove all even-valued elements from the list.

Preserve the original order of the odd numbers.

For this exercise, practice deletion using STL iterators rather than using list::remove_if().
*/
#include<iostream>
#include<list>
using namespace std;
int main(){
    cout<<"Enter Number of Elements: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input";
        return 0;
    }
    list<int> myList;
    if(n!=0)
    cout<<"Enter Elements: ";
    for(int i = 0; i<n ; i++){
        int val; cin>>val; 
        myList.push_back(val);
    } int count = 0;
    for(auto it = myList.begin(); it != myList.end() ; ){
        if(*it%2 == 0){
            it = myList.erase(it);
        } else{
            ++it;
        }
    }
    cout<<"Result: \n";
    for(const int& i : myList){
        cout<<i<<" -> ";
    } cout<<"NULL";
    return 0;
}
