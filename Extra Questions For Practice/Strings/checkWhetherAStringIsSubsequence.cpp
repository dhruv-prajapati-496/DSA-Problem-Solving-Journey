//Check Whether a String Is a Subsequence
//Problem statement
//Given two strings s and t, determine whether s is a subsequence of t.
//A subsequence is formed by deleting zero or more characters without changing the relative order of the remaining characters.
//Characters do not need to be adjacent.
//The comparison is case-sensitive, and spaces are treated as ordinary characters.
#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter String S: ";
    string s; getline(cin,s);
    cout<<"Enter String T: ";
    string t; getline(cin,t);
    if(s==""){
        cout<<"true";
        return 0;
    }
    int j = 0;
    for(int i = 0; i<t.size(); i++){
        if(j<s.size() && s[j] == t[i]){
            j++;
        }
    }
    if(j == s.size()){
        cout<<"true";
    } else{
        cout<<"false";
    }
    return 0;
}