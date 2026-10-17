#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array Elements: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int ans = 1, temp = 1;
    for(int i = 1; i<n; i++){
        if(arr[i] > arr[i-1]) ans++;
        else temp = max(ans,temp), ans = 1; 
    }
    if(ans >= temp) 
    cout<<"Longest Contiguous array size is: "<<ans;
    else cout<<"Longest Contiguous array size is: "<<temp; 
    return 0;
}