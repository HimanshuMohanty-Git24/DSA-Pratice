//100324. Clear Digits
#include<bits/stdc++.h>
using namespace std;
string clearDigits(string s) {
        int i=0;
        while(i<s.length()){
            if(isdigit(s[i])){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i-1);
                i=0;
            }
            i++;
        }
        return s;
}
int main()
{
    string s;
    s = "abc";
    cout<<clearDigits(s);
   return 0;
}