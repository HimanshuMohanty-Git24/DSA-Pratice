//2485. Find the Pivot Integer
#include<bits/stdc++.h>
using namespace std;
int pivotInteger(int n) {
    int sum = (n + 1) * n / 2;
    int pivot = (int)sqrt(sum);
    return pivot * pivot == sum ? pivot : -1;
}//Time complexity: O(1) Space complexity: O(1)
int pivotInteger1(int n){
    for (int i = 1; i <= n; i++)
    {
        long long left_sum = (i*(i+1))/2;
        long long right_sum = ((n*(n+1))/2)-(i*(i-1)/2);
        if(left_sum == right_sum){
            return i;
        }
    }
    return -1;
}//Time complexity: O(n) Space complexity: O(1)
int main()
{
    int n;
    cin>>n;
    cout<<pivotInteger(n)<<endl;
    cout<<pivotInteger1(n);
   return 0;
}