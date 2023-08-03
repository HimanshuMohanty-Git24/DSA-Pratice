//11. Container With Most Water
#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int i =0;
    int j=height.size()-1;
    int maxArea=0;
    while(i<j)
    {
        int area=min(height[i],height[j])*(j-i);
        maxArea=max(maxArea,area);
        if(height[i]<height[j])
            i++;
        else
            j--;
    }
    return maxArea;
}
int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}