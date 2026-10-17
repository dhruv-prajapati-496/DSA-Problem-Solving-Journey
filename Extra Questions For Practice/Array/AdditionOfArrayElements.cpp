// Addition of Array Elements
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Enter Number of Elements in Array: "<<endl;
    int n,sum = 0; cin>>n;
    vector<int> arr(n,0);
    cout<<"Enter Elements: "<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    cout<<"Sum of Elements: "<<sum; 
    return 0;
}   // can we use char to add (yes)
    // 