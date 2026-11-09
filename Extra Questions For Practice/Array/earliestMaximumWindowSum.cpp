/*
Earliest Maximum Window Sum
Problem Statement
You are given a vector of integers arr and an integer k. Consider every contiguous subarray of length exactly k. Find the maximum sum among all such windows, and return the 0-based starting index of the earliest window that achieves this maximum sum.
If k <= 0 or k > n (where n is the size of arr), return -1.
*/
#include<iostream>
#include<vector>
using namespace std;
int solution(const vector<int> &arr, int k){
    if(k<=0 || k>arr.size()){
        return -1;
    }
    int ans = 0;
    long long maxSum = 0, currSum = 0;
    for(int i = 0; i<k; i++){
        currSum += arr[i];
    }
    maxSum = currSum;
    for(int i = k; i<arr.size(); i++){
        currSum = currSum + arr[i] - arr[i-k];
        if(currSum > maxSum){
            maxSum = currSum;
            ans = i-k+1;
        }
    }
    return ans;
}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    if(n<0){
        cout<<"Invalid Input";
        return 0;
    }
    if(n>0) cout<<"Enter Array Elements: \n";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Window Size: ";
    int k; cin>>k;
    cout<<"Output: "<<solution(arr,k);
    return 0;
}