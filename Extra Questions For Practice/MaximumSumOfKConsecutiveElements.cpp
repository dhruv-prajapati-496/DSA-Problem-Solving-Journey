// Maximum sum of k consecutive elements
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n; cout<<"Enter Array Size: ";
    cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    long long sum = 0;
    long long maxSum = INT_MIN;
    int k; cout<<"Enter Number of Elements to Find Maximum Sum of Contiguous Subarray: ";
    cin>>k;
    if(k<=0 || k>n){
        cout<<"Invalid Value of K";
        return 0;
    }
    for(int i = 0; i<k; i++){
        sum+=arr[i];
    }
    maxSum = sum;
    for(int i = k; i<arr.size(); i++){
        sum = sum - arr[i-k] + arr[i];
        if(maxSum <=sum){
            maxSum = sum;
        }
    }
    cout<<"Answer: "<<maxSum;
}