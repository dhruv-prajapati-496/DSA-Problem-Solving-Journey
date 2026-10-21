//Maximum Sum After Removing One Element
//Given an integer vector arr of size n ≥ 2, remove exactly one element so that the sum of all remaining elements is as large as possible.
//Print the maximum remaining sum and the index of the removed element. If several removals produce the same maximum sum, choose the earliest index.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int ans = 0, n; long long maxSum = 0;
    cout<<"Enter Array Size: ";
    cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        maxSum+=arr[i];
        if(arr[i]< arr[ans]){
            ans = i;
        }
    }
    maxSum = maxSum - arr[ans];
    cout<<"Maximum Sum: "<<maxSum<<endl;
    cout<<"Removed Index: "<<ans;
    return 0;
}