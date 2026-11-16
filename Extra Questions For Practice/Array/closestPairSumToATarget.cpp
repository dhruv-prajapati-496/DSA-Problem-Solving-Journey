/*
Closest Pair Sum to a Target
Given a sorted integer vector arr and an integer target, 
find the minimum absolute difference between target and the sum of any two elements at distinct indices.
Return that minimum difference, not the pair itself.
Constraints
- 2 ≤ n ≤ 100000
- -100000 ≤ arr[i] ≤ 100000
- -200000 ≤ target ≤ 200000
- The array is sorted in non-decreasing order.
- Duplicate values are allowed, but both elements must come from different indices.
Requirements: O(n) time and O(1) auxiliary space. Do not use nested loops or sort the array again. Use long long for intermediate arithmetic.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int closestPairSumToATarget(const vector<int> &arr, int tar){
    int i = 0,j=arr.size()-1; long long ans = INT_MAX;
    long long sum = 0;
    while(i<j){
        sum = ((long long)arr[i] + arr[j]);
        long long diff = llabs(sum - tar);
        if(arr[i]+arr[j] == tar){
            return 0;
        }
        if(arr[i] + arr[j] > tar){
            ans = min(ans,diff);
            j--; continue;
        }
        if(arr[i] + arr[j] < tar){
            ans = min(ans,diff);
            i++;
        }
    }
    return ans;
}
int main(){
    cout<<"Enter Array size: ";
    int n; cin>>n;
    if(n>0) cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int tar; cout<<"Enter Target: ";
    cin>>tar;
    cout<<"Output: "<<closestPairSumToATarget(arr,tar);
    return 0;
}