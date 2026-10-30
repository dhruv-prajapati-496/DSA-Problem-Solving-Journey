/*
Maximum Sum of K Consecutive Elements Containing No Negative Numbers
Given an integer vector arr and an integer k,
find the maximum sum of any contiguous subarray of exactly k elements in which every element is non-negative (zero or positive).
If no such window exists, return -1.
*/
#include<iostream>
#include<vector>
using namespace std;
long long Solution(const vector<int>& arr, int k){
    int negCount = 0;
    long long maxSum = -1, currSum = 0;

    for(int i = 0; i<k; i++){
        currSum += arr[i];
        if(arr[i] < 0){
            negCount++;
        }
    }
    
    if(negCount == 0){
        maxSum = currSum;
    }

    for(int i = k; i<arr.size(); i++){
        currSum = currSum + arr[i] - arr[i-k];
        if(arr[i] < 0){
            negCount++;
        }
        if(arr[i-k]<0){
            negCount--;
        }
        if(negCount == 0 && currSum > maxSum){
            maxSum = currSum;
        }
    }

    return maxSum;
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
    cout<<"Result: "<<Solution(arr, k);
    return 0;
} // completed in O(n) time and O(1) space.