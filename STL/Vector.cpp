#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);//Faster than push back

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(3,4);//Diffrent syntax than push_back

    vector<int> v(5,100);//{100,100,100,100,100}


   return 0;
}
//What is a vector?
//Vector is a dynamic array which can grow and shrink its size.
//What is the time complexity of vector?
//Time complexity of vector is O(1) for insertion and deletion at the end and O(n) for insertion and deletion at the middle.
//What is the space complexity of vector?
//Space complexity of vector is O(n).
//What is the difference between vector and array?
//Array is static and vector is dynamic.
//What does vector use in  the background?
//Vector uses dynamic array in the background. 
//Use of vector ?
//Vector is used when we don't know the size of the array in advance.