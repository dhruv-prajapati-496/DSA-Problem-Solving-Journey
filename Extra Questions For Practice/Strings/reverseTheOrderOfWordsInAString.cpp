/*
Reverse the Order of Words
Problem Statement
Given a string s containing words separated by one or more spaces (possibly with leading and trailing spaces),
return a string with the words in reverse order, separated by exactly one space, with no leading or trailing spaces.
program can be complete within O(n) time & Space
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter A String: ";
    string str; getline(cin,str);
    string ans = "";
    string word = "";
    for(int i = 0; i<str.size(); i++){
        if(str[i] == ' '){
            if(!word.empty()){
                if(!ans.empty()) ans = word + " " + ans;
                else ans = word;
                word = "";
            }
            continue;
        }
        word+=str[i];
    }  
    if(!word.empty()){
        if(!ans.empty()) ans = word + " " + ans;
        else ans = word;
    }
    cout<<"Output: \n"<<ans;
    return 0;
}