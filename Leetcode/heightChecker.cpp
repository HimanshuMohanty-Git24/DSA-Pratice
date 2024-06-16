//1051. Height Checker
#include<bits/stdc++.h>
using namespace std;
int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(),temp.end());
        int ctr=0;
        for(int i=0;i<temp.size();i++){
            if(heights[i]!=temp[i]){
                ctr++;
            }
        }
        return ctr;
}
int main()
{
    vector<int> heights = {1,1,4,2,1,3};
    cout<<heightChecker(heights);
   return 0;
}