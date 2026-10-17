#include<iostream> 
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    cout<<"Enter Array Elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    vector<int> Output(n);
    for(int i = 0; i<n; i++){
        arr[i] = arr[i]*arr[i];
    }
    int st = 0, end = n-1, pos = n-1;
    while(st<=end){
        if(arr[st] > arr[end]){
            Output[pos] = arr[st];
            st++;
        }
        else{
            Output[pos] = arr[end];
            end--;
        }
        pos--;
    }
    cout<<"Output: ";
    for(int i : Output){
        cout<<i<<" ";
    }
    return 0;
}