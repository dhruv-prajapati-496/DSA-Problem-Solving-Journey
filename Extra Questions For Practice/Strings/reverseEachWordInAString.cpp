/*
Reverse Each Word in a String
Given a string s containing words separated by spaces,
reverse the characters of each individual word without changing the order of the words.
Every space must remain at its original position.
Constraints
- 0 ≤ s.length() ≤ 100000
- The string contains English letters and spaces.
- There may be leading, trailing, or multiple consecutive spaces.
Requirements: O(n) time and O(1) auxiliary space. Modify the original string. Do not create a second string or vector of words.
*/
#include<iostream>
#include<string>
using namespace std;
string reverseEachWordInAString(string &str){
    int n = str.length();
    int i = 0; 
    while(i<n){
        if(str[i] == ' '){
            i++; continue;
        }

        int left = i;

        while(i<n && str[i]!=' '){
             i++;
        }
        int right = i-1;
        while(left<right){
            swap(str[left],str[right]);
            left++;
            right--;
        }
    }

    return str;
}
int main(){
    cout<<"Enter A String: ";
    string str; getline(cin,str);
    cout<<"Outut: \n"<<reverseEachWordInAString(str);
    return 0;
}