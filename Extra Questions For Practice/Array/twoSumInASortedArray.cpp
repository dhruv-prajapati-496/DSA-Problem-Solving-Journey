// Two Sum in a Sorted Array
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter target: ";
    int t; cin>>t;
    int st = 0, end = n-1;
    while(st<end){
        int sum = arr[st] + arr[end];
        if(sum == t){
            cout<<"Answer: "<<st<<" "<<end;
            return 0;
        }
        else if(sum>t){
            end--;
        } else{
            st++;
        }
    }
    cout<<"Elements Not Found in Array: ";
    return 0;
}