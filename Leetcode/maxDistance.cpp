//1552. Magnetic Force Between Two Balls
#include<bits/stdc++.h>
using namespace std;
int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
    int n=position.size();
    int low=1;
    int high=position[n-1]-position[0];
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        int count=1;
        int prev=position[0];
        for (int i = 1; i < n; i++)
        {
            if(position[i]-prev>=mid){
                count++;
                prev=position[i];
            }
        }
        if(count>=m){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> position={1,2,3,4,7};
    int m=3;
    cout<<maxDistance(position,m);
   return 0;
}