//Intersection of Two Sorted Arrays
//You're given two integer vectors a and b, both sorted in non-decreasing order.
//Find the elements appearing in both arrays and return them in a new sorted vector.
//Important: If an element appears multiple times, include it as many times as it appears in both arrays, up to the smaller frequency.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Size of Array A: ";
    int n; cin>>n;
    cout<<"Enter Array A Elements: ";
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter Size of Array B: ";
    int m; cin>>m;
    cout<<"Enter Array B Elements: ";
    vector<int> b(m);
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    vector<long long> ans;
    int i = 0, j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            i++;
        }
        else if( a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++; j++;
        }
    }
    cout<<"Answer: { ";
    for(int i:ans){
        cout<<i<<" ";
    } cout<<"}";
    return 0;
}