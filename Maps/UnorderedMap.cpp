//Unordered Map
//Unordered map uses hashing in the background
#include<bits/stdc++.h>
using namespace std;
void print(unordered_map<int,string> &m)
{
    cout<<m.size()<<endl;
    for(auto &i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int main()
{
    unordered_map<int,string> m;
    m[1]="abc";
    m[5]="cdc";
    m[3]="acd";
    m.insert({2,"bcd"});
    m.insert({4,"cde"});
    auto it=m.find(5);
    m.erase(it);
    m.erase(3);
    if(it==m.end())
    {
        cout<<"No value\n";
    }
    else
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    print(m);
    return 0;
}