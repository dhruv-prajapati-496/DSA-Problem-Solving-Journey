//Minimum Sum of K Consecutive Elements
//Given an integer vector arr and an integer k, find the minimum sum of any contiguous subarray containing exactly k elements.
//Also return the starting index of that subarray. If multiple windows have the same minimum sum, return the earliest starting index.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
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
    if(k>n || k<=0){
        cout<<"Invalid Input";
        return 0;
    }
    long long minSum = INT_MAX, sum = 0; int idx = 0;
    for(int i = 0; i<k; i++) sum+=arr[i];
    if(minSum>sum) minSum = sum;
    for(int i = k; i<n ; i++){
        sum = sum + arr[i] - arr[i-k];
        if(sum < minSum){
            minSum = sum;
            idx = i - k + 1;
        }
    }
    cout<<"Minimum Sum of "<<k<<" Consecutive Elements is: "<<minSum<<endl;
    cout<<"Starting Index: "<<idx;
    return 0;
}