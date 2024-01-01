//455. Assign Cookies
#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int ctr = 0;
    int i = 0, j = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            ctr++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return ctr;
}
/*
Logic:
Sort both the arrays.
Now, iterate over both the arrays and check if the cookie size is greater than or equal to the greed factor.
If yes, then increment the counter and move to the next cookie and greed factor.
If no, then move to the next cookie.
*/
//Time Complexity: O(nlogn) Space Complexity: O(1)
int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << findContentChildren(g, s);
    return 0;
}