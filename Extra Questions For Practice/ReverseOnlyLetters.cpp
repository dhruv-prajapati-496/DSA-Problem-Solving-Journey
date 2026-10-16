// Reverse Only Letters : Explanation : 
//Given a string s, reverse only its English letters (A–Z, a–z).
// Every digit, space, and special character must remain at its original index.
//Input:  "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
using namespace std;
string ReverseOnlyLetters(string& str,int st,int end){
    while(st < end){
        if(!isalpha((unsigned char)str[st])){
            st++; continue;
        }
        if(!isalpha((unsigned char)str[end])){
            end--; continue;
        }
    if (isalpha((unsigned char)str[st]) && isalpha((unsigned char)str[end])) {
    char temp = str[st];
    str[st] = str[end];
    str[end] = temp;
        } st++; end--;
    }
    return str;
}
int main(){
    cout<<"Enter a String: ";
    string str; getline(cin,str);
    int end = str.size()-1;
    cout<<"The Result is : "<<ReverseOnlyLetters(str, 0 ,end);
    return 0;
    
}