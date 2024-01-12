// 1235. Maximum Profit in Job Scheduling
#include <bits/stdc++.h>
using namespace std;
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();

    vector<vector<int>> jobs(n, vector<int>(3));

    for (int i = 0; i < n; ++i)
    {
        jobs[i] = {endTime[i], startTime[i], profit[i]};
    }

    sort(jobs.begin(), jobs.end());

    map<int, int> dp = {{0, 0}};
    for (auto &job : jobs)
    {

        int cur = prev(dp.upper_bound(job[1]))->second + job[2];

        if (cur > dp.rbegin()->second)
        {
            dp[job[0]] = cur;
        }
    }
    int max = dp.rbegin()->second;
    return max;

} // Time Complexity: O(nlogn) and Space Complexity: O(n)
int memo[50001];
int n;
int getNextIndex(vector<vector<int>> &array, int l, int currentJobEnd)
{
    int r = n - 1;

    int result = n + 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (array[mid][0] >= currentJobEnd)
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return result;
}

int solve(vector<vector<int>> &array, int i)
{
    if (i >= n)
        return 0;

    if (memo[i] != -1)
        return memo[i];

    int next = getNextIndex(array, i + 1, array[i][1]);

    int taken = array[i][2] + solve(array, next);
    int notTaken = solve(array, i + 1);

    return memo[i] = max(taken, notTaken);
}

int jobScheduling2(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    n = startTime.size();

    memset(memo, -1, sizeof(memo));

    vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}

    for (int i = 0; i < n; i++)
    {
        array[i][0] = startTime[i];
        array[i][1] = endTime[i];
        array[i][2] = profit[i];
    }

    auto comp = [&](auto &vec1, auto &vec2)
    {
        return vec1[0] <= vec2[0];
    };

    sort(begin(array), end(array), comp);

    return solve(array, 0);
}

int main()
{
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    cout << jobScheduling2(startTime, endTime, profit);
    return 0;
}