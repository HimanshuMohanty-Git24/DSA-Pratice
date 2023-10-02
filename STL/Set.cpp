#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.emplace(2);//Faster than insert
    s.insert(3);
    s.emplace(4);//Faster than insert
    s.insert(5);
    s.emplace(6);//Faster than insert
    s.insert(1);//Duplicate elements are not allowed

    for(auto i:s)
    {
        cout<<i<<" ";
    }

    s.erase(1);//Erase element 1
    s.find(2);//Find element 2

    s.count(2);//Count element 2
   return 0;
}
//What is set?
//Set is a data structure which is similar to vector but in this data structure elements are arranged in increasing order.
//no duplicate elements are allowed in set.
//What is uses in the background of set?
//Set uses balanced binary search tree in the background.
//What is the time complexity of set?
//Insertion,deletion and searching takes O(logn) time in set.
//What is the difference between set and vector?
