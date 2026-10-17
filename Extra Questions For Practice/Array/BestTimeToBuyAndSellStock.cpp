#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    cout<<"Enter Array Size: ";
    int n; cin>>n;
    vector<int> arr(n);
    cout<<"Enter Array Elements: ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    } int ans = 0, minPrice = INT_MAX;
    for(int price : arr){
        if(price < minPrice){
            minPrice = price;
        } else if( price - minPrice > ans){
            ans = price - minPrice;
        }
    }
    cout<<"The Maximum Profit is: "<<ans;
    return 0;
}