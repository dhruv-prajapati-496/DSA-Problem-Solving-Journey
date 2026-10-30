/*
Move All Digits to the End of a String
Given a string s containing letters, digits, spaces, and special characters,
move all digits to the end of the string while preserving the original relative order of both digits and non-digits.
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter a String: \n";
    string str; getline(cin,str);
    string ans ="";
    for(int i = 0; i<str.size(); i++){
        if(str[i] < 48 || str[i] > 57){
            ans.push_back(str[i]);
        }
    }
    for(int i = 0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            ans.push_back(str[i]);
        }
    }
    cout<<"Result: \n"<<ans;
    return 0;
} // completed in O(n) time and O(n) space. 