//2235. Add Two Integers
#include<bits/stdc++.h>
using namespace std;
int sum(int num1, int num2) {
        return num1+num2;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int res =sum(n,m);
    cout<<res;
    return 0;
}