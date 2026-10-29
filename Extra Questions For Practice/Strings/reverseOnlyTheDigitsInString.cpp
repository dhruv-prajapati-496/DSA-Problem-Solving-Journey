/*
Reverse Only the Digits in a String
Given a string s containing letters, digits, spaces, and special characters, reverse only its digits while keeping every non-digit character in its original position.

You must modify the original string using Two Pointers.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    cout<<"Enter a String: ";
    string str; getline(cin,str);
    int i = 0, j = str.size()-1;
    while(i<j){
        if(str[i] < 48 || str[i] > 57){
            i++; continue;
        }
        if(str[j] < 48 || str[j] > 57){
            j--; continue;
        }
        swap(str[i],str[j]);
        i++; j--;
    }
    cout<<"Result: \n";
    cout<<str;
    return 0;
}