#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Elements: ";
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Position to Rotate The Array: ";
    int k; cin>>k;
    k = k%n;
        for(int i = 0; i<k; i++){
            int first = arr[0];
            arr.erase(arr.begin());
            arr.push_back(first);
        }
    
    cout<<"Rotated Array Is: ";
    for(int i : arr){
        cout<<i<<" ";
    }
}