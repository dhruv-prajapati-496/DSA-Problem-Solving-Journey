//Build a Prefix Sum Array
//Problem statement
//Given an integer vector arr, create a new vector prefix such that:
//prefix[i] contains the sum of all elements from index 0 through index i, inclusive.
//This technique is called a Prefix Sum.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    if(n<=0){
        cout<<"Invalid Input";
        return 0;
    }
    
    vector<int> arr(n);
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    if(n==1){
        vector<int> prefixSum = {arr[0]};
        cout<<"Prefix Sum Array is: "<<prefixSum[0];
        return 0;
    }
    long long sum = 0;
    vector<long long> prefixSum(n);
    for(int i = 0; i<n; i++){
        sum+= arr[i];
        prefixSum[i] = sum;
    }
    cout<<"Prefix Sum Array is: \n";
    for(int i = 0; i<n; i++){
        cout<<prefixSum[i]<<" ";
    }
}