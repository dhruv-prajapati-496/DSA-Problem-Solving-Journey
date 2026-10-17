//Count Subarrays of Size K With Sum at Least Target
//Given an integer vector arr, a window size k, and an integer target,
//count how many contiguous subarrays of exactly k elements have a sum greater than or equal to target.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;       // 6
    vector<int> arr(n,0);
    cout<<"Enter Array Elements: ";                          // [2, 1, 5, 1, 3, 2]
    for(int i = 0; i<n; i++){   
        cin>>arr[i];
    }
    cout<<"Enter Subarray Size: "; int k; cin>>k;           // 3
    if(k<=0 || k>n){
        cout<<"Invalid Input";
        return 0;
    }
    cout<<"Enter Target: "; int tar; cin>>tar;              // 7
    long long sum = 0; int count=0;
    for(int i= 0; i<k; i++){
        sum+=arr[i];
    } if(sum >= tar) count++;
    for(int i = k; i<n; i++){
        sum = sum + arr[i] - arr[i-k];
        if(sum >= tar) count++;
    }
    cout<<"Output : "<<count;                              // 3
    return 0;

}