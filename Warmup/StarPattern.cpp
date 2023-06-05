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
    cout<<"Pattern 10:"<<endl;
    char crt='A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
           cout<<crt<<" ";
        }
        crt++;
        cout<<endl;
    }
    cout<<"Pattern 11:"<<endl;
    char box='A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
           cout<<box<<" ";
           box++;
        }
        cout<<endl;
    }
    cout<<"Pattern 12:"<<endl;
    int x=65;
    for (int i = 1; i <= n; i++)
    {
        char ch=x+i-1;
        for (int j = 1; j <= i; j++)
        {
           cout<<ch<<" ";
           ch++;
        }
        cout<<endl;
    }
    cout<<"Pattern 13:"<<endl;
    int y=65;
    for (int i = n; i >= 1; i--)
    {
        char ch=y+i-1;
        for (int j = i; j <= n; j++)
        {
           cout<<ch<<" ";
           ch++;
        }
        cout<<endl;
    }
    cout<<"Pattern 14:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<"Pattern 15:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int star = n-i+1;;
        while(star){
            cout<<"*";
            star--;
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<"Pattern 16:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int space = i-1;;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= n-i+1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<"Pattern 17:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int space = i-1;;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= n-i+1; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    cout<<"Pattern 18:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    cout<<"Pattern 17:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int val=i;
        int space = i-1;;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= n-i+1; j++)
        {
            cout<<val;
            val++;
        }
        cout<<endl;
    }
    cout<<"Pattern 18:"<<endl;
    int z=1;
    for (int i = 1; i <= n; i++)
    {
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<z;
            z++;
        }
        cout<<endl;
    }
    cout<<"Pattern 19:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        int z=1;
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<z;
            z++;
        }
        for (int k = i-1; k!=0; k--)
        {
            cout<<k;
        }
        cout<<endl;
    }
    cout<<"Pattern 20:"<<endl<<endl;
    int i = 1;

    while (i <= n)
    {
        int Lctr = 1;
        int j = 1;
        while (j <= n - i + 1) // Left Counter part
        {
            cout << Lctr;
            Lctr++;
            j++;
        }
        int Lstar = i - 1;
        while (Lstar) // Left Star Part
        {
            cout << "*";
            Lstar--;
        }
        int Rstar = i - 1;
        while (Rstar) // Right Star Part
        {
            cout << "*";
            Rstar--;
        }
        int Rctr = n - i + 1;
        int k = 1;
        while (k <= n - i + 1)
        {
            cout << Rctr;
            Rctr--;
            k++;
        }

        cout << endl;
        i++;
    }
   return 0;
}