// Move all Target Elements To The End
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Target Element to Move: ";
    int tar; cin>>tar;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != tar){
            arr[j] = arr[i];
            j++;
        }
    }
    while (j < n)
    {
        arr[j] = tar;
        j++;
    }
    
    cout<<"Result: ";
    for(int i: arr){
        cout<<i<<" ";
    }
    return 0;
}