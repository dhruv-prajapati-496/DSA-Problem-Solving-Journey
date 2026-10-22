//Count Prefixes With Sum Greater Than or Equal to Target
//Given an integer vector arr and an integer target, count how many non-empty prefixes of the array have a sum greater than or equal to target.
//A prefix starts at index 0 and ends at some index i.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target: "; 
    long long tar; cin>>tar;
    long long prefixSum = 0; int ans = 0;
    for(int i : arr){
        prefixSum += i;
        if(prefixSum >= tar){
            ans++;
        }
    }
    cout<<"Answer: "<<ans; 
    return 0;
}