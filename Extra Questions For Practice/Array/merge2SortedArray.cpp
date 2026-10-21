//Merge Two Sorted Arrays
//Given two integer vectors a and b, both sorted in non-decreasing order, merge them into one new sorted vector.
//You must not use sort() or any other sorting algorithm.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter size of array A: ";
    int n; cin>>n;
    vector<int> a(n);
    cout<<"Enter Array A Elements: ";
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Enter size of array B: ";
    int m; cin>>m;
    vector<int> b(m); 
    cout<<"Enter Array B Elements: ";
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    vector<int> ans;
    int i = 0, j =0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++; 
        }
        else{
            ans.push_back(b[j]);
            j++;
        }

    }
    while(i<a.size()){
        ans.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        ans.push_back(b[j]);
            j++;
    }
    cout<<"The Sorted Merged Array is: ";
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}