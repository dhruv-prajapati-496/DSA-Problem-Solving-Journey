// Check If Array Is Sorted And Rotated
//Given an integer vector arr,
//determine whether it can be obtained by rotating a non-decreasing sorted array any number of positions, including zero rotations.
//Duplicates are allowed.
#include<iostream>
#include<vector>
using namespace std;
bool checkSortedAndRotated(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > arr[(i+1)%n]){
            count++;
        }
    }
    return count<=1;
}
int main(){
    cout<<"Enter Array Size: ";                 // 5
    int n; cin>>n;
    cout<<"Enter Array Elements: ";             // 4 5 1 2 3
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    if(checkSortedAndRotated(arr)){
        cout<<"True";
    } else{
        cout<<"False";
    }                                           // True
    return 0;
}