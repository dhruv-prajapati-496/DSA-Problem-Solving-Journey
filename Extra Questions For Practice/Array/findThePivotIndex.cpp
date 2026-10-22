// Find The Pivot Index.
//Given an integer vector arr, find the leftmost pivot index.
//An index i is a pivot if:
//- The sum of all elements strictly to its left equals the sum of all elements strictly to its right.
//- The element at index i itself is excluded from both sums.
//If no pivot exists, return -1.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n); long long sum = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    } int idx = -1; 
    long long leftSum = 0;
    for(int i = 0; i<n; i++){
        long long rightSum = sum - leftSum - arr[i];
        if(leftSum == rightSum){
            idx = i;
            break;
        } leftSum += arr[i];
    }
    cout<<"Answer: "<<idx;
    return 0;

}