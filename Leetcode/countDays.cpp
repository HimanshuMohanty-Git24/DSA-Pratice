/*
100311. Count Days Without Meetings
User Accepted:12299
User Tried:18581
Total Accepted:13437
Total Submissions:50155
Difficulty:Medium
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

 

Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.

 

Constraints:

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
*/
#include<bits/stdc++.h>
using namespace std;
int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(),meetings.end());

    int count=0;
    int n=meetings.size();
    int i=0;
    int j=0;

    while(i<days)
    {
        if(j<n && i>=meetings[j][0] && i<=meetings[j][1])
        {
            i=meetings[j][1]+1;
            j++;
        }
        else
        {
            count++;
            i++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> meetings={{5,7},{1,3},{9,10}};
    cout<<countDays(10,meetings);
   return 0;
}