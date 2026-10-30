/*
Count Equilibrium Indices
Given an integer vector arr, count how many indices satisfy the equilibrium condition:

The sum of elements strictly to the left of index i equals the sum of elements strictly to its right.

Unlike Day 16, which asked for the rightmost equilibrium index, today's problem asks for the total number of qualifying indices.
*/
#include<iostream>
#include<vector>
using namespace std;
int Solution(const vector<int> arr, long long Sum){
    int count = 0;
    long long rightSum = 0, leftSum = 0;
    for(int i = 0; i<arr.size(); i++){
        rightSum = Sum - leftSum - arr[i];
        if(leftSum == rightSum){
            count++;
        }
        leftSum += arr[i];
    }
    return count;
}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    long long Sum = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        Sum += arr[i];
    }
    cout<<"Result: \n"<<Solution(arr, Sum);
    return 0;
} // completed O(n) time & O(1) space.