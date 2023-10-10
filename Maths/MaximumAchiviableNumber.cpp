//2769. Find the Maximum Achievable Number
#include<bits/stdc++.h>
using namespace std;
int theMaximumAchievableX(int num, int t) {
    return num+(2*t);
}
int main()
{
    int num,t;
    cin>>num>>t;
    cout<<theMaximumAchievableX(num,t);
   return 0;
}