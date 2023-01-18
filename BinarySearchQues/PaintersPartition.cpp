#include <bits/stdc++.h>
using namespace std;
bool isPossible(int barrier, vector<int> boards, int n, int k)
{
    int painterCtr = 1;
    int boardsAllocated = 0;
    for (int i = 0; i < n; i++)
    {
        if (boards[i] > barrier)
        {
            return false;
        }
        if (boardsAllocated + boards[i] > barrier)
        {
            painterCtr++;
            boardsAllocated = boardsAllocated + boards[i];
        }
        else
        {
            boardsAllocated = boardsAllocated + boards[i];
        }
    }
    if (painterCtr > k)
    {
        return false;
    }
    return true;
}
int findLargestMinDistance(vector<int> boards, int n, int k)
{
    int ans;
    int low = *min_element(boards.begin(), boards.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + boards[i];
    }
    int high = sum;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (isPossible(mid, boards, n, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}
int main()
{
    vector<int> arr = {5, 5, 5, 5};
    int n = arr.size();
    cout << "Enter the number of painter" << endl;
    int k;
    cin >> k;
    int res = findLargestMinDistance(arr, n, k);
    cout << "Min time to paint all board:" << res;
    return 0;
}