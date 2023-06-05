#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Pattern 1:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    cout<<"Pattern 2:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<"Pattern 3:"<<endl;
    int count=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<count++<<" ";
        }
        cout<<endl;
    }
    cout<<"Pattern 4:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i + j - 1 << " ";
        }
        cout << endl;
    }
    cout<<"Pattern 5:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int val=i;
        for (int j = 1; j <= i; j++)
        {
            cout <<val<< " ";
            val--;
        }
        cout << endl;
    }
   return 0;
}