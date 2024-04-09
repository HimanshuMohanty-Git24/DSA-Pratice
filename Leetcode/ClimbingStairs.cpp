//70. Climbing Stairs
#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
    long long one = 1, two = 1;
    for (int i = 0; i < n; i++) {
        long long temp = one;
        one = one + two;
        two = temp;
    }
    return two;
}//Time Complexity: O(n) Space Complexity: O(1)
int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
   return 0;
}