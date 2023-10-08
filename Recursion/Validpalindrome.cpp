//125. Valid Palindrome
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    if(s.length()<=1){
        return true;
    }
    int st=0,end=s.length()-1;
    while(st<end){
        while(st<end&&!isalnum(s[st])) st++;
        while(st<end&&!isalnum(s[end])) end--;
        if(st<end &&tolower(s[st])!=tolower(s[end])){
            return false;
        }
        st++;
        end--;
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    if(isPalindrome(s))
        cout<<"true";
    else
        cout<<"false";
   return 0;
}