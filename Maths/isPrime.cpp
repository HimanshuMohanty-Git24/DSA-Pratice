#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n==1)
        return false;
    for (int i = 2; i*i <= n; i++)//we can also use i*i<=n instead of i<=sqrt(n)
    {
        if(n%i==0)//if any number divides n then it is not prime
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    if(isPrime(n))
        cout<<"Prime";
    else
        cout<<"Not Prime";
   return 0;
}