//605. Can Place Flowers
#include<bits/stdc++.h>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count=0;
    for(int i=0;i<flowerbed.size();i++)
    {
        if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0))
        {
            flowerbed[i]=1;
            count++;
        }
    }
    if(count>=n)
        return true;
    else
        return false;
}
int main()
{
    vector<int> flowerbed={1,0,0,0,1};
    int n=2;
    if(canPlaceFlowers(flowerbed,n))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
