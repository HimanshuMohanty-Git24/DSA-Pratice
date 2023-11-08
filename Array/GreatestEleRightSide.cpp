// 1299. Replace Elements with Greatest Element on Right Side
#include <bits/stdc++.h>
using namespace std;
vector<int> replaceElements(vector<int> &a)
{
    int n = a.size();
    vector<int> ans;
    int mx = a[n - 1];
    ans.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        ans.push_back(mx);
        if (a[i] >= mx)
        {

            mx = a[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    vector<int> ans = replaceElements(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}