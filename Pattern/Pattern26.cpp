/*
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
*/
#include<bits/stdc++.h>
using namespace std;
void pattern(int n)
{
    int i , j;
    for( i=0;i<2*n-1;i++){
        for ( j = 0; j < 2*n-1; j++)
        {
            int top =i;
            int left =j;
            int bottom = 2*n-2-i;
            int right = 2*n-2-j;
            cout<<(n-min(min(top,left),min(bottom,right)))<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    pattern(n);
    return 0;
}