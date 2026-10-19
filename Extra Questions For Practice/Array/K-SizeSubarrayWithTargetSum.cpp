//Find the First K-Size Subarray With Target Sum
//Given an integer vector arr, a window size k, and an integer target, 
//find the starting index of the first contiguous subarray of exactly k elements whose sum equals target.
//If no such subarray exists, return -1.
#include<iostream>
#include<vector>
using namespace std;
int KSizeSubarray(const vector<int>& arr, int k, int tar){
    long long sum = 0;
    for(int i = 0; i<k ; i++){
        sum+= arr[i];
    }
    if(sum==tar){
        return 0;
    }
    for(int i = k; i<arr.size(); i++){
        sum = sum + arr[i] - arr[i-k];
        if(sum == tar){
            return i-k+1;
        }
    }
    return -1;
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
    if(k<=0 || k>n){
        cout<<"Invalid Input";
        return 0;
    }
    cout<<"Enter Target: ";
    int tar; cin>>tar;
    cout<<"Answer: "<<KSizeSubarray(arr, k, tar);
    return 0;
}