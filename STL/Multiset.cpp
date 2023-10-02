#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> s;    
    s.insert(1);
    s.emplace(2);//Faster than insert
    s.insert(3);
    s.emplace(4);//Faster than insert
    s.insert(5);
    s.emplace(6);//Faster than insert
    s.insert(1);//Duplicate elements are allowed
   return 0;
}