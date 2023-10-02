#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second<p2.second)
    {
        return true;
    }
    if(p1.second>p2.second)
    {
        return false;
    }
    if(p1.first>p2.first)
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> v={2,1,5,10,4,6};
    sort(v.begin(),v.end());//Sorts the vector in ascending order
    sort(v.begin(),v.end(),greater<int>());//Sorts the vector in descending order
    sort(v.begin(),v.end(),less<int>());//Sorts the vector in ascending order

    pair<int,int> p[]={{1,2},{3,1},{5,0}};
    sort(p,p+3,comp);//Sorts the pair in descending order of second element and if second element is same then in ascending order of first element

    int num=7;
    int cnt=__builtin_popcount(num);//Returns the number of set bits in the binary representation of num

    string s="123";
    do{
        cout<<s<<endl;//Prints all the permutations of the string
    }while(next_permutation(s.begin(),s.end()));//Returns true if the next permutation is possible else returns false

    int arr[]={1,2,3,4,5};
    int max=*max_element(arr,arr+5);//Returns the maximum element in the array
   return 0;
}