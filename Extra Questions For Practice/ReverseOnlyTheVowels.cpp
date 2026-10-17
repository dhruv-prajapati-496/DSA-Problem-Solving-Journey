//Given a string s, reverse only the vowels in the string while keeping every other character in its original position.
//Vowels are a, e, i, o, u, including their uppercase versions
#include<iostream>
#include<string>
using namespace std;
int main(){
    cout<<"Enter A String: ";
    string str; getline(cin,str);
    int st = 0, end = str.size()-1;
    while(st<end){
        if(str[st] != 'a' && str[st] != 'e' && str[st] != 'i' && str[st] != 'o' && str[st] != 'u' && str[st] != 'A' && str[st] != 'E' && str[st] != 'I' && str[st] != 'O' && str[st] != 'U'){
            st++; continue; 
        }
        else if(str[end] != 'a' && str[end] != 'e' && str[end] != 'i' && str[end] != 'o' && str[end] != 'u' && str[end] != 'A' && str[end] != 'E' && str[end] != 'I' && str[end] != 'O' && str[end] != 'U'){
            end--; continue; 
        }
        else{
            char temp = str[st];
            str[st] = str[end];
            str[end] = temp;
        }
        st++; end--;
    }
    cout<<"The Reversed Vowel String is: \n"<<str;
    return 0;
}