/*
Maximum Sum of K Consecutive Even Numbers
Given an integer vector arr and an integer k, find the maximum sum among all contiguous subarrays of exactly k elements where every element is even.

If no such subarray exists, print -1.

Even numbers may be positive, negative, or zero.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
long long maximumSumOfConsecutiveEvenElements(vector<int> arr, int k){
    int n = arr.size();
    if(k<=0 || k>n){
        return -1;
    }

    long long currSum = 0;
    int oddCount = 0;
    for(int i = 0; i<k ; i++){
        currSum += arr[i];
        if(arr[i]%2!=0){
            oddCount++;
        }
    }

    long long maxSum = LLONG_MIN;
    bool found = false;

    if(oddCount == 0){
        maxSum = currSum;
        found = true;
    }

    for(int i = k; i<n; i++){
        int outgoing = arr[i-k];
        currSum -= outgoing;
        if(outgoing%2!=0) oddCount--;

        int incoming = arr[i];
        currSum += incoming;
        if(incoming%2!=0) oddCount++;

        if(oddCount == 0){
        if(!found || currSum > maxSum){
            maxSum = currSum;
        }
        found = true;
    }
    }
    return found ? maxSum: -1;
    
}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter value of K: ";
    int k; cin>>k;
    if(k<=0 || k>n){
        cout<<"Invalid Input: ";
        return 0;
    }
    cout<<"Result: "<<maximumSumOfConsecutiveEvenElements(arr,k);
    return 0;
}