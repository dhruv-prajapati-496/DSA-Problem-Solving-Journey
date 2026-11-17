/*
Check Whether Two Strings Are Anagrams
Given two lowercase English strings s and t, determine whether they are anagrams of each other.
Two strings are anagrams if they contain exactly the same characters with exactly the same frequencies, regardless of order.
Return true if they are anagrams; otherwise, return false.
Constraints: 0 ≤ s.length(), t.length() ≤ 100000. Both strings contain only lowercase English letters.
Requirements: O(n + m) time and O(1) auxiliary space, where n and m are the two string lengths. Do not use sort().
Edge cases: Different string lengths, empty strings, repeated characters, same letters with different frequencies.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool checkAnagram(const string &str1, const string &str2){
    if(str1.size() != str2.size()){
        return "false";
    }
    int freq1[26] = {0};
    int freq2[26] = {0};
    for(int i = 0; i<str1.size(); i++){
        freq1[str1[i] - 'a']++;
        freq2[str2[i] - 'a']++;
    }
    for(int i = 0; i<26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;

}
int main(){
    cout<<"Enter String 1: ";
    string str1,str2; getline(cin,str1);
    cout<<"Enter String 2: ";
    getline(cin,str2);
    cout<<"Output: "<<boolalpha<<checkAnagram(str1,str2);
    return 0;
}