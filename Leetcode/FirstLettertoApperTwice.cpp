//2351. First Letter to Appear Twice
#include<bits/stdc++.h>
using namespace std;
char repeatedCharacter(string s) {
        unordered_set<char> letters;
        for (char ch : s) {
            if (letters.find(ch) != letters.end()) {
                return ch;
            }
            letters.insert(ch);
        }
        return '\0';
}
int main()
{
    string s;
    cin>>s;
    cout<<repeatedCharacter(s);
   return 0;
}