/*
Minimum Length Subarray With Sum at Least Target
Given a vector arr containing only positive integers and a positive integer target, find the length of the shortest contiguous subarray whose sum is greater than or equal to target.
Return 0 if no such subarray exists.
Constraints: 1 ≤ n ≤ 100000, 1 ≤ arr[i] ≤ 10000, 1 ≤ target ≤ 1000000000.
Requirements: O(n) time and O(1) auxiliary space. 
Do not use nested loops to check every subarray. Use long long for sums and const vector<int>& for the array parameter.
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int Solution(const vector<int> &arr, int tar){
    int left = 0;
    long long currSum = 0;
    int minLen = INT_MAX;
    for(int right = 0; right<arr.size();right++){
        currSum+=arr[right];
        while(currSum>=tar){
            int currLen = right - left + 1;
            minLen = min(minLen,currLen);
            currSum -= arr[left];
            left++;
        }

    }
    return (minLen == INT_MAX) ? 0 : minLen;

}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    if(n>0) cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target: ";
    int tar; cin>>tar;
    if(tar<0){
        cout<<"Invalid Input: ";
        return 0;
    }
    cout<<"Output: "<<Solution(arr,tar);
    return 0;
}