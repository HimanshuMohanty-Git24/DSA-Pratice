#include<bits/stdc++.h>
using namespace std;
int main()
{
    //key,value
    map<int,int> m;
    map<int , pair<int,int>> mpp;
    map<pair<int,int>,int> mppp;

    m[1]=2;
    m.emplace(2,3);//Faster than insert
    m.insert({3,4});
   return 0;
}