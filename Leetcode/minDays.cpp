//1482. Minimum Number of Days to Make m Bouquets
#include<bits/stdc++.h>
using namespace std;
int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < m*k) return -1;
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while(l < r){
            int mid = l + (r-l)/2;
            int bouquets = 0, flowers = 0;
            for(int i = 0; i < n; i++){
                if(bloomDay[i] <= mid){
                    flowers++;
                    if(flowers == k){
                        bouquets++;
                        flowers = 0;
                    }
                }
                else flowers = 0;
            }
            if(bouquets < m) l = mid+1;
            else r = mid;
        }
        return l;
}
int main()
{
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    cout<<minDays(bloomDay, m, k);
   return 0;
}