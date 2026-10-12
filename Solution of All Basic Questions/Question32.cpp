// Move all zeros to end.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; cout<<"Enter Array Size: ";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Elements in Array: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];

    }
    int idx = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] != 0){
            arr[idx++] = arr[i];
        }
    }
    while(idx<n){
        arr[idx++]=0;
        }
    for(int num:arr)  cout<<num<<" ";
        
        return 0;
        } 