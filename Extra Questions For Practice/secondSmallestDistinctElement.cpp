// Finding second smallest element from an array without sorting it. 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    if(n<2){
        cout<<"Array Must Contain more than 2 values: ";
        return 0;
    }
    vector<int> arr(n,0);
    cout<<"Enter Array Elements: ";
    for(int i = 0 ; i<n; i++){
        cin>>arr[i];
    }
    int first = INT_MAX, second = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < first){
            second = first;
            first = arr[i];
        }  else if(arr[i]>first && arr[i]<second){
            second = arr[i];
        }
    }
    cout<<"The Second Smallest Element is : "<<second;
    return 0;
}