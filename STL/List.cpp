#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> ls;

    ls.push_back(1);
    ls.emplace_back(2);//Faster than push back

    ls.push_front(3);
    ls.emplace_front(4);//Faster than push front
   return 0;
}
//Difference between vector and list?
//Vector is a dynamic array and list is a doubly linked list.
//time complexity of vector and list?
//Time complexity of vector is O(1) for insertion and deletion at the end and O(n) for insertion and deletion at the middle.