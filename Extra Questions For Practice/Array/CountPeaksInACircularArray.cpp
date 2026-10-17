//Count Peaks in a Circular Array
//Given an integer vector arr, imagine its elements are arranged in a circle.
//An element is called a peak if it is strictly greater than both its immediate neighbors.
//Your task is to count the number of peaks.
//Because the array is circular, the first element's left neighbor is the last element, and the last element's right neighbor is the first element.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n,count = 0; cin>>n; 
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<"Number of Peak Elements: "<<0;
        return 0;
    }
    if(arr[0] > arr[1] && arr[0] > arr[n-1]){
        count++;
    } 
    for(int i = 1; i<n; i++){
    if(arr[i] > arr[(i+1)%n] && arr[i] > arr[i-1]){
        count++;
    }
    }
    cout<<"Number of Peak Elements: "<<count;
    return 0;
}