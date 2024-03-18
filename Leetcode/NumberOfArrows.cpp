//452. Minimum Number of Arrows to Burst Balloons
#include<bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end());
    int res = points.size();
    int prev = points[0][1];
    for(int i=1;i<points.size();i++){
        int curr = points[i][0];
        if(curr<=prev){
            res--;
            prev = min(points[i][1], prev);
        }
        else{
            prev = points[i][1];
        }
    }
    return res;
}
int main()
{
    //[[10,16],[2,8],[1,6],[7,12]]
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout<<findMinArrowShots(points)<<endl;
    //[[1,2],[3,4],[5,6],[7,8]]
    points = {{1,2},{3,4},{5,6},{7,8}};
    cout<<findMinArrowShots(points)<<endl;
    //[[1,2],[2,3],[3,4],[4,5]]
    points = {{1,2},{2,3},{3,4},{4,5}};
    cout<<findMinArrowShots(points)<<endl;
    return 0;
}