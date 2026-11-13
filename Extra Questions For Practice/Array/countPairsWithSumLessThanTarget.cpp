/*
Count Pairs with Sum Less Than Target
Problem Statement
Given an array arr sorted in non-decreasing order and an integer target, 
count the number of pairs (i, j) with i < j such that arr[i] + arr[j] < target.
within O(n) time and O(1) Space
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter array Size: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input";
        return 0;
    }
    if(n>0) cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target: ";
    int k; cin>>k;
    int i = 0, j = n-1; long long count = 0;
    while(i<j){
        if(arr[i] + arr[j] < k){
            count+= (j-i);
            i++; 
        }
        else{
            j--;
        }
    }
    cout<<"\nOutput: "<<count;
    return 0;
}