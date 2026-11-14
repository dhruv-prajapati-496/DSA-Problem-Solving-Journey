/*
Longest Subarray with Sum at Most Target (Array, familiar pattern you need practice in)
Problem Statement
Given a vector of positive integers arr and an integer target, return the length of the longest contiguous subarray whose sum is <= target. 
If no such subarray exists (e.g., every element is greater than target), return 0.
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    vector<int> arr(n);
    if(n>0) cout<<"Enter array Elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target: ";
    int tar; cin>>tar;
    int maxLength = 0, left = 0;
    long long currSum = 0;
    for(int i = 0; i<n; i++){
        currSum += arr[i];

        while(currSum > tar && left <= i){
            currSum -= arr[left];
            left++;
        }
        maxLength = max(maxLength,i-left+1);
    }
    cout<<"Output: "<<maxLength;
    return 0;
}