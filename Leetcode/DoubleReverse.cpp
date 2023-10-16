//2119. A Number After a Double Reversal
#include<bits/stdc++.h>
using namespace std;
bool isSameAfterReversals(int num) {
    int rev = 0;
    int temp = num;
    while(temp>0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    if(rev == num){
        return true;
    }
    temp = rev;
    rev = 0;
    while(temp>0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    if(rev == num){
        return true;
    }
    return false;
}
int main()
{
    int num;
    cin>>num;
    cout<<isSameAfterReversals(num);
   return 0;
}