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
    cout<<"Enter Element to Remove: ";
    int k; cin>>k;
    int j = 0; 
    for(int i = 0; i<n; i++){
        if(arr[i]!=k){
            arr[j] = arr[i];
            j++;
        }
    } arr.resize(j);
    cout<<"Result : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
    
}