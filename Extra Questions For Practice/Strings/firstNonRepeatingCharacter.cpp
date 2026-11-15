/*
First Non-Repeating Character
Given a string s containing only lowercase English letters (a to z), 
return the index of the first character that appears exactly once in the entire string.
If no such character exists, return -1.
Constraints: 0 ≤ s.length() ≤ 100000. All characters are lowercase English letters.
Requirements: O(n) time and O(1) auxiliary space. 
Return the index, not the character. Avoid checking every character against the entire string.
*/
#include<iostream>
#include<string>
using namespace std;
int firstNonRepeatingCharacter(const string &str){
    if(str.length() == 1) return 0;
    if(str.empty()) return -1;

    int freq[26] = {0};
    for(char c : str){
        freq[c-'a']++;
    }

    for(int i = 0; i<str.length(); i++){
        if(freq[str[i] - 'a'] == 1) return i;
    }

    return -1;

}
int main(){
    cout<<"Enter a String: ";
    string str; getline(cin,str);
    cout<<"Output: "<<firstNonRepeatingCharacter(str);
    return 0;
}