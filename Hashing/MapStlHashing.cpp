#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    //pre compute
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }//We can do the same for characters as well using map<char,int> m; m[s[i]]++;

    //query
    cout<<"Enter the number of queries: ";
    int q;
    cin>>q;
    cout<<"Enter the number to be searched: ";
    while(q--)
    {
        int x;
        cin>>x;
        cout<<x<<" "<<m[x]<<endl;
    }
   return 0;
}//Time complexity: O(nlogn) for precomputation and O(1) for query
//Unordered map is used for O(1) time complexity for both precomputation and query worst case is o(n) due to collision