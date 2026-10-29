/*
Find the Equilibrium Index
Given an integer vector arr, find the rightmost equilibrium index.

An index i is an equilibrium index when the sum of all elements strictly to its left equals the sum of all elements strictly to its right.

If multiple equilibrium indices exist, return the rightmost one. If none exist, return -1.
*/
#include<iostream>
#include<vector>
using namespace std;
int findTheEquillibriumIndex(vector<int> arr){
    int idx = -1; long long maxSum = 0;
    for(int i: arr){
        maxSum+=i;
    }
    long long rightSum = 0, leftSum = 0;
    for(int i = 0 ; i<arr.size(); i++){
        rightSum = maxSum - leftSum - arr[i];
        if(leftSum == rightSum){
            idx = i;
        } leftSum += arr[i];
    }
    return idx;
}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0 ; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Answer: "<<findTheEquillibriumIndex(arr);
    return 0;
}