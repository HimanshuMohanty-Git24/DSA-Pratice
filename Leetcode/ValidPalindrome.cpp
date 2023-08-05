//125. Valid Palindrome
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string inputString) {
        int i=0,j=inputString.length()-1;
        while(i<j){
            if(!isalnum(inputString[i])){
                i++;
            }
            else if(!isalnum(inputString[j])){
                j--;
            }
            else if(tolower(inputString[i])!=tolower(inputString[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
}
int main()
{
    string s="0P";
    if(isPalindrome(s)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
   return 0;
}