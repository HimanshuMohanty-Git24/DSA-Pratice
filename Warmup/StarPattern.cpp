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
    cout<<"Pattern 6:"<<endl;
    char c='A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<c<<" ";
        }
        c++;
        cout<<endl;
    }
    cout<<"Pattern 7:"<<endl;
    for (int i = 0; i < n; i++)
    {
        char c='A';
        for (int j = 0; j < n; j++)
        {
           cout<<c<<" ";
           c++;
        }
        cout<<endl;
    }
    cout<<"Pattern 8:"<<endl;
    char ch='A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<ch<<" ";
           ch++;
        }
        cout<<endl;
    }
    cout<<"Pattern 9:"<<endl;
    int chr=65;
    for (int i = 1; i <= n; i++)
    {
        char ch=chr+i-1;
        for (int j = 1; j <= n; j++)
        {
           cout<<ch<<" ";
           ch++;
        }
        cout<<endl;
    }
   return 0;
}