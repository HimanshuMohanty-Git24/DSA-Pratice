#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.emplace(2);//Faster than insert
    s.insert(3);

    s.erase(1);//Erase element 1

    s.find(2);//Find element 2
   return 0;
}