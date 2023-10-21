//2124. Check if All A's Appears Before All B's
#include<bits/stdc++.h>
using namespace std;
bool checkString(string s) {
    for (int i = 1; i < s.length(); i++)
    {
        if(s[i-1]>s[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    cout<<checkString(s);
    return 0;
}