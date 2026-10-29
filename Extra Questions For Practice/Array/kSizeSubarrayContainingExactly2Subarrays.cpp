/*
Count K-Size Subarrays Containing Exactly Two Odd Numbers
Given an integer vector arr and integer k, count how many contiguous subarrays of exactly k elements contain exactly two odd numbers.

Odd numbers may be positive or negative.
*/
#include<iostream>
#include<vector>
using namespace std;
int Solution(vector<int> arr, int k){
    int oddCount = 0, ans = 0;
    for(int i = 0; i<k; i++){
        if(arr[i]%2 != 0){
            oddCount++;
        }
    }
    if(oddCount == 2){
        ans = 1;
    }
    
    for(int i = k; i<arr.size() ; i++){
        if(arr[i]%2 != 0){
            oddCount++;
        }
        if(arr[i-k]%2 != 0){
            oddCount--;
        }
        if(oddCount == 2){
            ans++;
        }
    }
    return ans;
}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Window Size: ";
    int k; cin>>k;
    cout<<"Result: "<<Solution(arr,k);
    return 0; 
}