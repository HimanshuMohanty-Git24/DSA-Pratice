//2520. Count the Digits That Divide a Number
#include<bits/stdc++.h>
using namespace std;
int countDigits(int num) {
    int ctr=0;
    int temp=num;
    while (num>0)
    {
        int lastdigit = num%10;
        if(temp%lastdigit==0){
            ctr++;
        }
        num=num/10;
    }
    return ctr;
}
int main()
{
    int num;
    cin>>num;
    cout<<countDigits(num);
   return 0;
}