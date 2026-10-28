/*
Merge Two Sorted Strings
You're given two strings a and b, each containing only lowercase English letters. The characters in both strings are already sorted in alphabetical order.

Your task is to merge them into one alphabetically sorted string without using any sorting algorithm.

Preserve all characters, including duplicates.
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter String 1: \n";
    string str1; getline(cin,str1);
    cout<<"Enter String 2: \n";
    string str2; getline(cin,str2);
    string answer = "";
    int i = 0, j = 0;
    while(i<str1.length() && j<str2.length()){
        if(str1[i] <= str2[j]){
            answer.push_back(str1[i]);
            i++;
        }
        else{
            answer.push_back(str2[j]);
            j++;
        }
    }
    while(i<str1.length()){
        answer.push_back(str1[i]);
        i++;
    }
    while(j<str2.length()){
        answer.push_back(str2[j]);
        j++;
    }
    cout<<"Result: \n"<<answer;
    return 0;
}