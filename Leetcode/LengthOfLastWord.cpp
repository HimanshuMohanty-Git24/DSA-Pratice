//58. Length of Last Word
#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) {
        int len = 0;
        bool counting = false;
        for(int i = s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                counting = true;
                len++;
            }
            else if(counting){
                break;
            }
        }
        return len;
}
int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLastWord(s)<<endl;
   return 0;
}