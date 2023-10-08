#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int hash[100]={0};
    for(int i=0;i<n;i++)
    {
        hash[a[i]]++;
    }
    //Frequency of each number
    for(int i=0;i<100;i++)
    {
        if(hash[i]!=0)
        {
            cout<<i<<" "<<hash[i]<<endl;
        }
    }
    return 0;
}