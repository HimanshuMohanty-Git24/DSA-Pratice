#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(long long x){
        long long temp=x;
        long long rev=0;
        if(x<0){
            return false;
        }
        else{
            while(x>0){
                long long lastdigit = x%10;
                rev = (rev*10)+lastdigit;
                x=x/10;
            }
            if(rev>INT_MAX||rev<INT_MIN) return 0;
            if(temp==rev){
                return true;
            }
            else{
                return false;
            }

        }
}
int main()
{
    int n;
    cin>>n;
    if(ispalindrome(n)){
        cout<<"Yes it's palindrome";
    }
    else{
        cout<<"No it's not a palindrome";
    }
   return 0;
}