//1235. Maximum Profit in Job Scheduling
#include<bits/stdc++.h>
using namespace std;
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        map<int, int> dp = {{0, 0}};
        for(auto& job : jobs) {

            int cur = prev(dp.upper_bound(job[1]))->second + job[2];

            if(cur > dp.rbegin()->second) {
                dp[job[0]] = cur;
            }
        }
        int max =dp.rbegin()->second;
        return max;

}//Time Complexity: O(nlogn) and Space Complexity: O(n)
int main()
{
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout<<jobScheduling(startTime,endTime,profit);
    return 0;
}