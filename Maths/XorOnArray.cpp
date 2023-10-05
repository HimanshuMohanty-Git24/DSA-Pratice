//1486. XOR Operation in an Array
#include<bits/stdc++.h>
using namespace std;
int xorOperation(int n, int start) {
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int sum = start+2*i;
        arr.push_back(sum);
    }
    int res=arr[0];
    for (int i = 1; i < n; i++)
    {
        res = res^arr[i];
    }
    return res;
}
int main()
{
    int n,start;
    cin>>n>>start;
    cout<<xorOperation(n,start);
   return 0;
}