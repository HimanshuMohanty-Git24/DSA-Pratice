#include<bits/stdc++.h>
using namespace std;
bool isArmstrongNumber(long long n){
    int originalno = n;
    int count = 0;
    int temp = n;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    int sumofpower = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sumofpower += pow(digit,count);
        n /= 10;
    }
    return (sumofpower == originalno);
}
int main()
{
    int n;
    cin>>n;
    if(isArmstrongNumber(n)){
        cout<<"It's a Armstrong Number.";
    }
    else{
        cout<<"No it's not a Armstrong Number";
    }
   return 0;
}