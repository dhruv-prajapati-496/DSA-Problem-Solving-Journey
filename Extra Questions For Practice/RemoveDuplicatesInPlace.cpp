#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    vector<int> a(n);
    cout<<"Enter Elements in array: ";
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int k = 0;
    for(int i = 0; i<a.size(); i++){
        if(k==0 || a[i] != a[i-1]){
            a[k]=a[i];
            k++;
        }
    } 
    a.resize(k);
    cout<<"The Set of Elements in Array is: ";
    for(int i : a){
        cout<<i<<" ";
    }
    return 0;
}