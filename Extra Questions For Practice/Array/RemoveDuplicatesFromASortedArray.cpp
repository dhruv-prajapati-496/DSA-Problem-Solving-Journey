#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Values in Array: ";
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    } vector<int> result;
    for(int i = 0; i<arr.size(); i++){
        if(i==0 ||arr[i] != arr[i-1]){
            result.push_back(arr[i]);
        }
    }
    cout<<"The Set of Elements in Array is: ";
    for(int i : result){
        cout<<i<<" ";
    }
}