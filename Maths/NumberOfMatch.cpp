// 1688. Count of Matches in Tournament
#include <bits/stdc++.h>
using namespace std;
int numberOfMatches(int n)
{
    int teams = n;
    int matches = 0;
    int teamadv = 0;
    int totalMatch = 0;
    while (teams > 1)
    {
        if (teams % 2 == 0)
        {
            matches = teams / 2;
            teamadv = teams / 2;
        }
        else
        {
            matches = (teams - 1) / 2;
            teamadv = ((teams - 1) / 2) + 1;
        }
        totalMatch = totalMatch + matches;
        teams = teamadv;
    }
    return totalMatch;
} // Time complecity : O(logn) Space : O(1)
int main()
{
    int n;
    cin >> n;
    cout << numberOfMatches(n);
    return 0;
}