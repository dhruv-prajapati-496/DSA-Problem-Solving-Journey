//Range Sum Queries Using Prefix Sums
//Given an integer vector arr and q queries, each query contains two 0-based indices L and R.
//For every query, print the sum of all elements from index L through index R, inclusive.
//You must construct the prefix-sum array once, then answer each query efficiently.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    vector<long long> prefixSum(n);
    long long pSum = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        pSum+=arr[i];
        prefixSum[i] = pSum;
    }
    cout<<"Enter Number of Queries: ";
    int q; cin>>q; 
    vector<int> queries(q*2);
    cout<<"Enter Queries: "<<endl;
    for(int i = 0; i<queries.size(); i++){
        cin>>queries[i];
    }
    cout<<"Queries: ";
    for(int i = 0; i<queries.size(); i++){
        cout<<queries[i]<<" ";
    }
    for(int i:queries){
        if(i>=n || i<0){
            cout<<"Invalid Input";
            return 0;
        }
    }
    int left = 0, right = 1;
    cout<<"Answer: \n";
    while(right < queries.size()){
        int L = queries[left];
        int R = queries[right];
        if(L > R){
            cout<<"Invalid Input";
            return 0;
        }
        if(L == 0){
            cout<<prefixSum[R]<<endl;
            left +=2; right +=2;
            continue;
        } else{
        cout<<prefixSum[R] - prefixSum[L-1]<<endl;
        left +=2; right +=2; 
        }
    }
    return 0;
}