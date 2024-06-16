//344. Reverse String
#include<bits/stdc++.h>
using namespace std;
void reverseString(vector<char>& s) {
    int n = s.size();
    int i = 0;
    int j = n-1;
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}
int main()
{
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for(auto i:s)
    {
        cout<<i;
    }
   return 0;
}