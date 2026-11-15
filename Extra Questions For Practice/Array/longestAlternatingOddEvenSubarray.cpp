/*
Longest Alternating Odd-Even Subarray
Given an integer vector arr, find the length of the longest contiguous subarray in which the parity alternates between adjacent elements.
In other words, every pair of neighboring elements in the chosen subarray must contain one odd and one even number.
Constraints: 0 ≤ n ≤ 100000, -100000 ≤ arr[i] ≤ 100000.
Requirements: O(n) time and O(1) auxiliary space. No sorting, no additional array, and no nested loop.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LongestAlternatingOddEvenSubarray(const vector<int> &arr){
    if(arr.empty()) return 0;
    int ans = 1, curr = 1;
    for(int i = 1; i<arr.size();i++){
        if((arr[i]%2==0) != (arr[i-1]%2==0) ){
            curr++;
            ans = max(curr,ans);
        }
        else{
            curr = 1;
        }
    }
    return ans;
}
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    if(n > 0) cout<<"Enter Array Elements: \n";
    vector<int> arr(n);
    for(int i = 0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"Output: "<<LongestAlternatingOddEvenSubarray(arr);
    return 0;
}