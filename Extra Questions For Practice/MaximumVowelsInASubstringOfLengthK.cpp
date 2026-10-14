// Maximum Vowels in a Substring Of Length K.
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str; cout<<"Enter a String: ";
    getline(cin,str);
    for(char &c : str){
        if(c>='A' && c<='Z') c = c+32;
    }
    cout<<"Enter Maximum Length of Substring: ";
    int k; cin>>k;
    if(k<=0 || k>str.size()){
        cout<<"Invalid Input";
        return 0;
    }
    int maxVowels = 0;
    for(int i = 0; i<k; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            maxVowels++;
        }
    }
    int vowelCount = maxVowels;

    for(int i = k; i<str.size(); i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowelCount++;
        if(str[i-k] == 'a' || str[i-k] == 'e' || str[i-k] == 'i' || str[i-k] == 'o' || str[i-k] == 'u') vowelCount--;
        maxVowels = max(maxVowels,vowelCount);

    }
    cout<<"Result: "<<maxVowels;
    return 0;

}