#include<bits/stdc++.h>
using namespace std;
int calcGCD(int n, int m){
    while(n>0&&m>0){
        if(n>m){
            n=n%m;
        }
        else{
            m=m%n;
        }
    }
    if(n==0){
        return m;
    }
    else{
        return n;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int res =calcGCD(n,m);;
    cout<<res<<endl;
   return 0;
}
//Time Complexity: O(log(min(a, b)))