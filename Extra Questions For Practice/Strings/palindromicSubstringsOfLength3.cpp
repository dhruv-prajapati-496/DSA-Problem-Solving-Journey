/*
Palindromic Substrings of Length 3 (String, familiar pattern)
Problem Statement
Given a string s consisting only of lowercase English letters,
count how many substrings of length exactly 3 are palindromes. A palindrome reads the same forwards and backwards.
*/
#include<iostream>
#include<string>
using namespace std;
int Solution(const string &str){
    int count = 0;
    for(int i = 0; i<str.length()-2; i++){
        if(str[i] == str[i+2]){
            count++;
        }
    }
    return count;
}
int main(){
    cout<<"Enter a String: \n";
    string str; getline(cin, str);
    if(str.size() < 3){
        cout<<"Output: "<<0;
        return 0;
    }
    cout<<"Output: "<<Solution(str);
    return 0;
}
